#include "trie.h"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insertWord(const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (curr->children[index] == nullptr) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool Trie::searchWord(const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (curr->children[index] == nullptr) {
            return false;
        }
        curr = curr->children[index];
    }
    return curr != nullptr && curr->isEndOfWord;
}

bool Trie::deleteHelper(TrieNode* node, const std::string& word, int depth) {
    if (node == nullptr) {
        return false;
    }
    if (depth == word.size()) {
        if (!node->isEndOfWord) {
            return false;
        }
        node->isEndOfWord = false;
        // Check if current node has no children
        bool hasNoChildren = true;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                hasNoChildren = false;
                break;
            }
        }
        return hasNoChildren;
    }

    int index = word[depth] - 'a';
    if (deleteHelper(node->children[index], word, depth + 1)) {
        delete node->children[index];
        node->children[index] = nullptr;

        // Check if current node can be deleted (no children and not end of word)
        bool hasNoChildren = true;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                hasNoChildren = false;
                break;
            }
        }
        return !node->isEndOfWord && hasNoChildren;
    }
    return false;
}

bool Trie::deleteWord(const std::string& word) {
    return deleteHelper(root, word, 0);
}

void Trie::updateWord(const std::string& oldWord, const std::string& newWord) {
    deleteWord(oldWord);
    insertWord(newWord);
}