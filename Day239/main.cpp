#include <iostream>
#include <vector>
#include <queue>
#include <string>

// Aho-Corasick algorithm for multiple pattern matching using a trie with failure links.
// Time complexity: O(length of text + total length of patterns + number of matches).

struct Node {
    int next[26];      // transitions for 'a' to 'z'
    int link;          // failure link
    std::vector<int> out; // indices of patterns ending at this node

    Node() {
        std::fill(next, next + 26, -1);
        link = -1;
    }
};

class AhoCorasick {
public:
    std::vector<Node> trie;

    AhoCorasick() {
        trie.clear();
        trie.emplace_back(); // root
    }

    void addPattern(const std::string &s, int id) {
        int v = 0;
        for (char ch : s) {
            if (ch < 'a' || ch > 'z') continue; // skip non-lowercase
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = (int)trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].out.push_back(id);
    }

    void build() {
        std::queue<int> q;
        trie[0].link = 0;
        for (int c = 0; c < 26; ++c) {
            int u = trie[0].next[c];
            if (u != -1) {
                trie[u].link = 0;
                q.push(u);
            } else {
                trie[0].next[c] = 0;
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            int link = trie[v].link;

            for (int c = 0; c < 26; ++c) {
                int u = trie[v].next[c];
                if (u != -1) {
                    trie[u].link = trie[link].next[c];
                    // merge outputs from failure link
                    for (int id : trie[trie[u].link].out) {
                        trie[u].out.push_back(id);
                    }
                    q.push(u);
                } else {
                    trie[v].next[c] = trie[link].next[c];
                }
            }
        }
    }

    // Returns (patternId, endingIndex) pairs
    std::vector<std::pair<int, int>> search(const std::string &text, const std::vector<std::string> &patterns) {
        std::vector<std::pair<int, int>> matches;
        int v = 0;
        for (int i = 0; i < (int)text.size(); ++i) {
            char ch = text[i];
            if (ch < 'a' || ch > 'z') {
                v = 0; // reset on non-lowercase
                continue;
            }
            int c = ch - 'a';
            v = trie[v].next[c];
            for (int id : trie[v].out) {
                int len = (int)patterns[id].size();
                matches.push_back({id, i}); // pattern id ends at index i
            }
        }
        return matches;
    }
};

int main() {
    std::cout << "===== Aho-Corasick Multiple Pattern Matching Demo =====\n";

    int k;
    std::cout << "Enter number of patterns: ";
    std::cin >> k;

    if (k <= 0) {
        std::cout << "No patterns to match. Exiting.\n";
        return 0;
    }

    std::vector<std::string> patterns(k);
    std::cout << "Enter " << k << " patterns (lowercase letters only):\n";
    for (int i = 0; i < k; ++i) {
        std::cin >> patterns[i];
    }

    std::string text;
    std::cout << "Enter the text (lowercase letters only, no spaces): ";
    std::cin >> text;

    AhoCorasick ac;
    for (int i = 0; i < k; ++i) {
        ac.addPattern(patterns[i], i);
    }
    ac.build();

    auto matches = ac.search(text, patterns);

    if (matches.empty()) {
        std::cout << "No patterns found in the text.\n";
    } else {
        std::cout << "Matches found (pattern, start_index, end_index):\n";
        for (auto &m : matches) {
            int id = m.first;
            int endIdx = m.second;
            int startIdx = endIdx - (int)patterns[id].size() + 1;
            std::cout << "Pattern '" << patterns[id] << "' at [" << startIdx << ", " << endIdx << "]\n";
        }
    }

    return 0;
}
