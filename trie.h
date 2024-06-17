#ifndef TRIE_H
#define TRIE_H

#include <string>

class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26];

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    bool deleteHelper(TrieNode* node, const std::string& word, int depth);


    Trie();
    void insertWord(const std::string& word);
    bool searchWord(const std::string& word);
    bool deleteWord(const std::string& word);
    void updateWord(const std::string& oldWord, const std::string& newWord);
};

#endif // TRIE_H