#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->val) root->left = insertNode(root->left, v);
    else root->right = insertNode(root->right, v);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
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

    Node* root = nullptr;
    cout << "Binary Search Tree Demo\n";
    cout << "Menu:\n1) Insert value\n2) Inorder traversal (sorted)\n3) Preorder traversal\n4) Postorder traversal\n5) Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        int ch;
        if (!(cin >> ch)) break;
        if (ch == 5) break;

        if (ch == 1) {
            int x; cout << "Enter value to insert: "; cin >> x;
            root = insertNode(root, x);
            cout << "Inserted " << x << " into BST.\n";
        } else if (ch == 2) {
            cout << "Inorder: ";
            inorder(root);
            cout << '\n';
        } else if (ch == 3) {
            cout << "Preorder: ";
            preorder(root);
            cout << '\n';
        } else if (ch == 4) {
            cout << "Postorder: ";
            postorder(root);
            cout << '\n';
        } else {
            cout << "Invalid choice\n";
        }
    }

    freeTree(root);
    cout << "Goodbye!\n";
    return 0;
}