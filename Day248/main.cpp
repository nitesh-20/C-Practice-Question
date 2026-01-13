#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Medium level DSA: Top view of a binary tree
// We build a simple binary tree and print its top view using BFS

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

void topView(Node* root) {
    if (!root) return;

    // map: horizontal distance -> first node value seen at that distance
    map<int, int> hdToVal;

    // queue of pairs: (node pointer, horizontal distance)
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        Node* node = cur.first;
        int hd = cur.second;

        // if this horizontal distance is seen first time, store it
        if (hdToVal.find(hd) == hdToVal.end()) {
            hdToVal[hd] = node->val;
        }

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    cout << "Top view: ";
    for (auto &p : hdToVal) {
        cout << p.second << ' ';
    }
    cout << '\n';
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Top View of Binary Tree (using BFS + horizontal distance)\n";

    int n;
    cout << "Enter number of nodes to insert in BST: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid n. Exiting.\n";
        return 0;
    }

    Node* root = nullptr;
    cout << "Enter " << n << " integer values: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    topView(root);

    freeTree(root);
    return 0;
}
