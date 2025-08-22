#include <iostream>
#include "httplib.h"
#include "trie.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main()
{
    Trie trie;

    // Preload kuch demo words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("banana");
    trie.insert("band");
    trie.insert("bandana");

    httplib::Server svr;

    // --- CORS setup ---
    svr.set_pre_routing_handler([](const httplib::Request &req, httplib::Response &res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");

        if (req.method == "OPTIONS") {
            res.status = 204;  // No Content
            return httplib::Server::HandlerResponse::Handled;
        }
        return httplib::Server::HandlerResponse::Unhandled;
    });

    // --- Insert word (in-memory only, no file) ---
    svr.Post("/insert", [&](const httplib::Request& req, httplib::Response& res) {
        try {
            auto body = json::parse(req.body);
            std::string word = body["word"];
            trie.insert(word);   // ✅ only in TRIE, no file
            res.set_content(R"({"status":"word added"})", "application/json");
        } catch (...) {
            res.status = 400;
            res.set_content(R"({"error":"invalid request"})", "application/json");
        }
    });

    // --- Autocomplete search ---
    svr.Get(R"(/autocomplete/(.*))", [&](const httplib::Request &req, httplib::Response &res) {
        std::string prefix = req.matches[1];
        auto results = trie.autocomplete(prefix);
        nlohmann::json j = results;
        res.set_content(j.dump(), "application/json");
    });

    std::cout << "Server starting on http://0.0.0.0:8080\n";
    bool listening = svr.listen("0.0.0.0", 8080);
    if (!listening) {
        std::cerr << "Error: Server failed to start listening on port 8080\n";
        return 1;
    }
    std::cout << "Server stopped unexpectedly\n";
    return 0;
}
