#include <iostream>
#include <vector>
#include <string>

// Z-Algorithm for pattern matching
// Builds Z-array where Z[i] is the length of the longest substring
// starting at i that is also a prefix of the string.
// We use it on "pattern + special_char + text" to find matches.

std::vector<int> buildZ(const std::string &s) {
    int n = static_cast<int>(s.size());
    std::vector<int> z(n, 0);

    int l = 0, r = 0; // [l, r] is the current Z-box
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

std::vector<int> zAlgorithmSearch(const std::string &text, const std::string &pattern) {
    std::vector<int> positions;
    if (pattern.empty() || text.empty()) return positions;

    char sep = '#';
    // Ensure separator is not in pattern or text
    bool conflict = true;
    for (char c = '#'; c <= '~'; ++c) {
        if (pattern.find(c) == std::string::npos && text.find(c) == std::string::npos) {
            sep = c;
            conflict = false;
            break;
        }
    }
    if (conflict) {
        // Fallback: assume '#'
        sep = '#';
    }

    std::string combined = pattern + sep + text;
    std::vector<int> z = buildZ(combined);
    int m = static_cast<int>(pattern.size());

    for (int i = 0; i < static_cast<int>(combined.size()); ++i) {
        if (z[i] == m) {
            // i is index in combined; starting position in text:
            int posInText = i - m - 1; // minus pattern and separator
            if (posInText >= 0) positions.push_back(posInText);
        }
    }

    return positions;
}

int main() {
    std::cout << "===== Z-Algorithm String Matching Demo =====\n";

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

    std::vector<int> positions = zAlgorithmSearch(text, pattern);

    if (positions.empty()) {
        std::cout << "Pattern not found in the text.\n";
    } else {
        std::cout << "Pattern found at positions (0-based indices): ";
        for (size_t i = 0; i < positions.size(); ++i) {
            std::cout << positions[i];
            if (i + 1 < positions.size()) std::cout << ", ";
        }
        std::cout << "\n";
    }

    return 0;
}
