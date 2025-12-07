#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (c < 'a' || c > 'z') continue; // ignore non-lowercase letters
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(const string& word) const {
        TrieNode* node = root;
        for (char c : word) {
            if (c < 'a' || c > 'z') return false;
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(const string& prefix) const {
        TrieNode* node = root;
        for (char c : prefix) {
            if (c < 'a' || c > 'z') return false;
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;
    cout << "Trie Dictionary Demo (lowercase words)\n";
    cout << "Menu:\n1) Insert word\n2) Search word\n3) Starts with prefix\n4) Exit\n";

    int choice;
    string s;
    while (true) {
        cout << "\nEnter choice: ";
        if (!(cin >> choice)) break;
        if (choice == 4) break;

        cout << "Enter lowercase word/prefix: ";
        cin >> s;

        if (choice == 1) {
            trie.insert(s);
            cout << "Inserted: " << s << "\n";
        } else if (choice == 2) {
            cout << (trie.search(s) ? "Found" : "Not found") << "\n";
        } else if (choice == 3) {
            cout << (trie.startsWith(s) ? "There exists a word starting with this prefix" : "No word with this prefix") << "\n";
        } else {
            cout << "Invalid choice\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}