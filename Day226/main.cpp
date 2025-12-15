#include <iostream>
#include <string>
#include <vector>

// Rabin-Karp string matching algorithm (simple version)
// Uses rolling hash to find all occurrences of a pattern in a text.
// Average Time: O(n + m), Worst-case: O(n * m) due to hash collisions.

const long long MOD = 1000000007LL; // large prime for modulo
const long long BASE = 257LL;       // base for polynomial rolling hash

long long modPow(long long a, long long e, long long mod) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return res;
}

std::vector<int> rabinKarp(const std::string &text, const std::string &pattern) {
    std::vector<int> positions;
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    if (m == 0 || m > n) return positions;

    long long patHash = 0;
    long long curHash = 0;

    // precompute BASE^(m-1) % MOD for rolling
    long long highestPow = modPow(BASE, m - 1, MOD);

    // initial hashes for first window
    for (int i = 0; i < m; ++i) {
        patHash = (patHash * BASE + static_cast<unsigned char>(pattern[i])) % MOD;
        curHash = (curHash * BASE + static_cast<unsigned char>(text[i])) % MOD;
    }

    // slide the window over the text
    for (int i = 0; i <= n - m; ++i) {
        // if hash matches, verify characters to avoid false positives
        if (curHash == patHash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) positions.push_back(i);
        }

        // compute hash for next window
        if (i < n - m) {
            // remove leading char and add trailing char
            long long lead = (static_cast<long long>(static_cast<unsigned char>(text[i])) * highestPow) % MOD;
            curHash = (curHash - lead + MOD) % MOD; // remove leading
            curHash = (curHash * BASE + static_cast<unsigned char>(text[i + m])) % MOD; // add trailing
        }
    }

    return positions;
}

int main() {
    std::cout << "===== Rabin-Karp String Matching Demo =====\n";

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

    std::vector<int> positions = rabinKarp(text, pattern);

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
