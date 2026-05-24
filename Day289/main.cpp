#include <iostream>
#include <queue>

using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    
    Node(int val) {
        data = val;
        
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    // Helper functions for recursive operations
    Node* insertRec(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insertRec(node->left, data);
        } else if (data > node->data) {
            node->right = insertRec(node->right, data);
        }
        return node;
    }

    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    Node* searchRec(Node* node, int key) {
        if (node == nullptr || node->data == key) {
            return node;
        }
        if (node->data > key) {
            return searchRec(node->left, key);
        }
        return searchRec(node->right, key);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteRec(Node* node, int key) {
        if (node == nullptr) return node;

        if (key < node->data) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->data) {
            node->right = deleteRec(node->right, key);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertRec(root, data);
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorderRec(root);
        cout << endl;
    }

    bool search(int key) {
        return searchRec(root, key) != nullptr;
    }

    void remove(int key) {
        root = deleteRec(root, key);
    }

    void levelOrderTraversal() {
        if (root == nullptr) return;
        cout << "Level Order Traversal: ";
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            cout << current->data << " ";
            q.pop();

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    cout << "--- Binary Search Tree (BST) Operations ---" << endl;
    
    // Inserting elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Traversals
    bst.inorder();
    bst.levelOrderTraversal();

    // Searching
    int key = 60;
    cout << "Searching for " << key << ": " << (bst.search(key) ? "Found" : "Not Found") << endl;

    key = 90;
    cout << "Searching for " << key << ": " << (bst.search(key) ? "Found" : "Not Found") << endl;

    // Deletion
    cout << "Deleting 20..." << endl;
    bst.remove(20);
    bst.inorder();

    cout << "Deleting 30..." << endl;
    bst.remove(30);
    bst.inorder();

    cout << "Deleting 50 (Root)..." << endl;
    bst.remove(50);
    bst.inorder();

    return 0;
}
