#include <iostream>
#include <vector>
#include <string>

// KMP (Knuth-Morris-Pratt) Pattern Searching Algorithm
// Time: O(n + m), where n = text length, m = pattern length

// Build LPS (Longest Prefix Suffix) array
// lps[i] = length of the longest proper prefix of pattern[0..i]
//          which is also a suffix of pattern[0..i]
std::vector<int> buildLPS(const std::string &pat) {
    int m = static_cast<int>(pat.size());
    std::vector<int> lps(m, 0);

    int len = 0; // length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // try shorter prefix
                len = lps[len - 1];
            } else {
                // no prefix found
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP search: find all occurrences of pattern in text
std::vector<int> kmpSearch(const std::string &text, const std::string &pat) {
    std::vector<int> result;
    if (pat.empty()) return result; // empty pattern

    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pat.size());

    std::vector<int> lps = buildLPS(pat);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) {
            // pattern found at index (i - j)
            result.push_back(i - j);
            j = lps[j - 1]; // continue searching
        } else if (i < n && text[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}

int main() {
    std::cout << "===== KMP String Matching Demo =====\n";

    std::string text, pattern;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);

    if (text.empty()) {
        std::cout << "Text is empty. Exiting.\n";
        return 0;
    }

    std::cout << "Enter the pattern to search: ";
    std::getline(std::cin, pattern);

    if (pattern.empty()) {
        std::cout << "Pattern is empty. Nothing to search.\n";
        return 0;
    }

    std::vector<int> positions = kmpSearch(text, pattern);

    if (positions.empty()) {
        std::cout << "Pattern not found in the text.\n";
    } else {
        std::cout << "Pattern found at positions (0-based indices): ";
        for (size_t idx = 0; idx < positions.size(); ++idx) {
            std::cout << positions[idx];
            if (idx + 1 < positions.size()) std::cout << ", ";
        }
        std::cout << "\n";
    }

    return 0;
}
