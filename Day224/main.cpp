#include <iostream>
#include <vector>
using namespace std;

// Disjoint Set Union (Union-Find) with path compression and union by rank
class DSU {
    vector<int> parent, rankv;
public:
    DSU(int n = 0) { init(n); }

    void init(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }

    bool sameSet(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Disjoint Set Union (Union-Find) Demo\n";
    cout << "Enter number of elements (0..n-1): ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    DSU dsu(n);
    cout << "Menu:\n1) Union a b\n2) Check if a and b are in same set\n3) Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        int ch;
        if (!(cin >> ch)) break;
        if (ch == 3) break;

        int a, b;
        cout << "Enter a and b (0-based indices): ";
        cin >> a >> b;
        if (a < 0 || a >= n || b < 0 || b >= n) {
            cout << "Invalid indices.\n";
            continue;
        }

        if (ch == 1) {
            bool merged = dsu.unite(a, b);
            if (merged) cout << "Merged sets of " << a << " and " << b << "\n";
            else cout << a << " and " << b << " are already in the same set.\n";
        } else if (ch == 2) {
            cout << (dsu.sameSet(a, b) ? "YES, same set" : "NO, different sets") << "\n";
        } else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}