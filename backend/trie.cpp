#include "trie.h"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c]) node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->isEnd = true;
}

void Trie::dfs(TrieNode* node, std::string prefix, std::vector<std::string>& results) {
    if (!node) return;
    if (node->isEnd) results.push_back(prefix);
    for (const auto& child : node->children) {
        if (child.second) {  // extra safety check
            dfs(child.second, prefix + child.first, results);
        }
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
