#include "trie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Trie::Trie() { root = new TrieNode(); }

void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c]) node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->isEnd = true;
}

void Trie::dfs(TrieNode* node, const std::string& prefix, std::vector<std::string>& results) {
    if (!node) return;
    if (node->isEnd) results.push_back(prefix);
    for (const auto& child : node->children) {
        if (child.second) dfs(child.second, prefix + child.first, results);
    }
}

std::vector<std::string> Trie::autocomplete(const std::string& prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
        if (!node->children[c]) return {};
        node = node->children[c];
    }
    std::vector<std::string> results;
    dfs(node, prefix, results);
    return results;
}

// CLI wrapper (used by Node.js server)
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./trie [insert|autocomplete] <word/prefix>\n";
        return 1;
    }

    Trie trie;
    std::ifstream fin("words.txt");
    std::string w;
    while (fin >> w) trie.insert(w);
    fin.close();

    std::string command = argv[1];
    std::string input = argv[2];

    if (command == "insert") {
        trie.insert(input);
        std::ofstream fout("words.txt", std::ios::app);
        fout << input << "\n";
        fout.close();
        std::cout << "word added" << std::endl;
    } else if (command == "autocomplete") {
        auto results = trie.autocomplete(input);
        json j = results;
        std::cout << j.dump() << std::endl;
    } else {
        std::cerr << "Unknown command\n";
        return 1;
    }

    return 0;
}
