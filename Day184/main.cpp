#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

bool searchNode(Node* root, int val) {
    while (root) {
        if (root->val == val) return true;
        if (val < root->val) root = root->left;
        else root = root->right;
    }
    return false;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    cout << "Simple BST Demo\n";
    cout << "Menu:\n1) Insert\n2) Search\n3) Inorder Traversal\n4) Exit\n";
    int choice;
    while (true) {
        cout << "\nEnter choice: ";
        if (!(cin >> choice)) break;
        if (choice == 4) break;
        if (choice == 1) {
            int x; cout << "Enter value to insert: "; cin >> x;
            root = insertNode(root, x);
            cout << x << " inserted.\n";
        } else if (choice == 2) {
            int x; cout << "Enter value to search: "; cin >> x;
            bool found = searchNode(root, x);
            cout << (found ? "Found\n" : "Not found\n");
        } else if (choice == 3) {
            cout << "Inorder (sorted) traversal: ";
            inorder(root);
            cout << '\n';
        } else {
            cout << "Invalid choice\n";
        }
    }
    freeTree(root);
    cout << "Goodbye!\n";
    return 0;
}