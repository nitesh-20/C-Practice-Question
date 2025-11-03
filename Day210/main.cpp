#include <iostream>
#include <vector>
using namespace std;

// Segment Tree for Range Sum Query and Point Update
class SegmentTree {
    int n;
    vector<long long> tree;
public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        tree.assign(4 * max(1, n), 0);
        if (n > 0) build(1, 0, n - 1, arr);
    }
    void build(int node, int l, int r, const vector<long long>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node*2, l, mid, arr);
        build(node*2+1, mid+1, r, arr);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    long long query(int ql, int qr) { return queryRec(1, 0, n-1, ql, qr); }
    long long queryRec(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0; // no overlap
        if (ql <= l && r <= qr) return tree[node]; // total overlap
        int mid = (l + r) / 2;
        return queryRec(node*2, l, mid, ql, qr) + queryRec(node*2+1, mid+1, r, ql, qr);
    }

    void update(int idx, long long val) { updateRec(1, 0, n-1, idx, val); }
    void updateRec(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) updateRec(node*2, l, mid, idx, val);
        else updateRec(node*2+1, mid+1, r, idx, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Segment Tree (Range Sum Query & Point Update)\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n < 0) return 0;
    vector<long long> arr(n);
    if (n > 0) {
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; ++i) cin >> arr[i];
    }

    SegmentTree st(arr);

    cout << "Menu:\n1) Range sum query\n2) Point update\n3) Exit\n";
    while (true) {
        cout << "\nEnter choice: ";
        int choice;
        if (!(cin >> choice)) break;
        if (choice == 3) break;
        if (choice == 1) {
            cout << "Enter l r (0-based indices): ";
            int l, r; cin >> l >> r;
            if (l < 0) l = 0; if (r >= n) r = n-1;
            if (l > r) { cout << "Invalid range\n"; continue; }
            cout << "Range sum [" << l << "," << r << "] = " << st.query(l, r) << '\n';
        } else if (choice == 2) {
            cout << "Enter index and new value (0-based index): ";
            int idx; long long val; cin >> idx >> val;
            if (idx < 0 || idx >= n) { cout << "Invalid index\n"; continue; }
            st.update(idx, val);
            cout << "Updated index " << idx << " to " << val << '\n';
        } else {
            cout << "Invalid choice\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
