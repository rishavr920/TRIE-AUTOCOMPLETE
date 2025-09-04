#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>
#include <vector>

struct TrieNode {
    bool isEnd = false;
    std::unordered_map<char, TrieNode*> children;
};

class Trie {
private:
    TrieNode* root;
    void dfs(TrieNode* node, const std::string& prefix, std::vector<std::string>& results);

public:
    Trie();
    void insert(const std::string& word);
    std::vector<std::string> autocomplete(const std::string& prefix);
};

#endif
