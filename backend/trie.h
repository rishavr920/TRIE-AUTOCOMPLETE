#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
public:
    bool isEnd;
    std::unordered_map<char, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class Trie {
private:
    TrieNode* root;
    void dfs(TrieNode* node, std::string prefix, std::vector<std::string>& results);

public:
    Trie();
    void insert(const std::string& word);
    std::vector<std::string> autocomplete(const std::string& prefix);
};

#endif
