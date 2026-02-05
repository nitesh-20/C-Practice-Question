#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Medium level DSA: Level-order traversal + left and right view of a binary tree

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

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    cout << "Level-order traversal: ";
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        cout << cur->val << ' ';
        if (cur->left) q.push(cur->left);
        
        if (cur->right) q.push(cur->right);
    }
    cout << '\n';
}

void leftView(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    cout << "Left view: ";
    while (!q.empty()) {
        int sz = (int)q.size();
        for (int i = 0; i < sz; ++i) {
            Node* cur = q.front();
            q.pop();
            if (i == 0) cout << cur->val << ' ';
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    cout << '\n';
}

void rightView(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    cout << "Right view: ";
    while (!q.empty()) {
        int sz = (int)q.size();
        for (int i = 0; i < sz; ++i) {
            Node* cur = q.front();
            q.pop();
            if (i == sz - 1) cout << cur->val << ' ';
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
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

    cout << "===== Binary Tree Level Order + Left/Right View Demo =====\n";

    int n;
    cout << "Enter number of nodes to insert in BST: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid n. Exiting.\n";
        return 0;
    }

    Node* root = nullptr;
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    levelOrder(root);
    leftView(root);
    rightView(root);

    freeTree(root);
    return 0;
}
