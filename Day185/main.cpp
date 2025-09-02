#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool checkBalanced(const string& s) {
    stack<pair<char,int>> st; // char and position (0-based)
    for (int i = 0; i < (int)s.size(); ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push({c,i});
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                cout << "Not balanced: extra '" << c << "' at position " << i << "\n";
                return false;
            }
            auto [op,pos] = st.top(); st.pop();
            if (!matches(op,c)) {
                cout << "Not balanced: expected matching for '" << op << "' at position " << pos
                     << " but found '" << c << "' at position " << i << "\n";
                return false;
            }
        }
    }
    if (!st.empty()) {
        auto [op,pos] = st.top();
        cout << "Not balanced: missing closing for '" << op << "' opened at position " << pos << "\n";
        return false;
    }
    cout << "The expression is balanced.\n";
    return true;
}

int main() {
    cout << "Balanced Parentheses Checker\n";
    cout << "Enter an expression (may include (), [], {}):\n";
    string line;
    // read the whole line including spaces
    if (!std::getline(cin, line)) return 0;
    if (line.empty()) {
        cout << "No input provided. Exiting.\n";
        return 0;
    }
    checkBalanced(line);
    return 0;
}