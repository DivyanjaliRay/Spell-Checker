#include <iostream>
#include <vector>
#include <string>
#include "trie.h"

using namespace std;

int main() {
    Trie ot;
    // Create dictionary
    vector<string> words = {"cat", "car", "ball", "bat", "bats"};
    for (auto word : words) {
        ot.insertWord(word);
    }

    string s = "";
    char c;
    bool exitLoop = false;

    while (!exitLoop) {
        cout << "Choose an operation:\n";
        cout << "1. Search for a word\n";
        cout << "2. Delete a word\n";
        cout << "3. Update a word\n";
        cout << "4. Enter new input\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter a word to search: ";
                string word;
                cin >> word;
                ot.searchWord(word) ? cout << "Present\n" : cout << "Not Present\n";
                break;
            }
            case 2: {
                cout << "Enter a word to delete: ";
                string word;
                cin >> word;
                ot.deleteWord(word) ? cout << "Deleted\n" : cout << "Not Deleted\n";
                break;
            }
            case 3: {
                cout << "Enter the old word and the new word: ";
                string oldWord, newWord;
                cin >> oldWord >> newWord;
                ot.updateWord(oldWord, newWord);
                cout << "Update complete.\n";
                break;
            }
            case 4: {
                cout << "Enter new input:\n";
                s = "";
                cin.ignore(); // Clear the input buffer
                while ((c = getchar()) != EOF) {
                    if (c == '\n') {
                        ot.searchWord(s) ? cout << s : cout << s;
                        break;
                    } else if (c == ' ') {
                        ot.searchWord(s) ? cout << s : cout << s;
                        s = "";
                        cout << c;
                    } else {
                        s += c;
                    }
                }
                break;
            }
            case 5: {
                exitLoop = true;
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                break;
        }
    }

    return 0;
}