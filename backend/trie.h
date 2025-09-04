#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>
#include <vector>

// A single node in the Trie
struct TrieNode {
    bool isEnd = false;                                // Marks end of a word
    std::unordered_map<char, TrieNode*> children;      // Next characters
};

// Trie data structure supporting insert + autocomplete
class Trie {
private:
    TrieNode* root;

    // DFS helper for autocomplete
    void dfs(TrieNode* node, const std::string& prefix, std::vector<std::string>& results);

public:
    Trie();  // Constructor

    // Insert a word into the Trie
    void insert(const std::string& word);

    // Return all words starting with given prefix
    std::vector<std::string> autocomplete(const std::string& prefix);
};

#endif // TRIE_H
