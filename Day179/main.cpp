#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Simple search engine using hashmap (like Google search for keywords)
class SearchEngine {
    unordered_map<string, vector<string>> index;
public:
    void addDocument(const string& docName, const vector<string>& keywords) {
        for (const string& keyword : keywords) {
            index[keyword].push_back(docName);
        }
    }
    void search(const string& keyword) {
        cout << "Search results for '" << keyword << "':\n";
        if (index.count(keyword)) {
            for (const string& doc : index[keyword]) {
                cout << "- " << doc << endl;
            }
        } else {
            cout << "No results found." << endl;
        }
    }
};

int main() {
    SearchEngine engine;
    engine.addDocument("DSA Basics", {"array", "search", "sort"});
    engine.addDocument("Graph Algorithms", {"graph", "bfs", "dfs"});
    engine.addDocument("Sorting Techniques", {"sort", "bubble", "quick"});

    string query;
    cout << "Enter keyword to search: ";
    cin >> query;
    engine.search(query);
    return 0;
}