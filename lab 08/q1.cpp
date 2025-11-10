#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key)
            return node;
        if (key < node->key)
            return search(node->left, key);
        return search(node->right, key);
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }

    void inorder() { inorder(root); }
    void preorder() { preorder(root); }
    void postorder() { postorder(root); }
};

int main() {
    BST tree;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    for (int key : elements)
        tree.insert(key);

    cout << "Inorder traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder();
    cout << endl;

    cout << "\nSearching for 40: ";
    cout << (tree.search(40) ? "Found" : "Not Found") << endl;

    cout << "\nDeleting 20...\n";
    tree.deleteKey(20);
    cout << "Inorder after deleting 20: ";
    tree.inorder();
    cout << endl;

    cout << "Deleting 30...\n";
    tree.deleteKey(30);
    cout << "Inorder after deleting 30: ";
    tree.inorder();
    cout << endl;

    cout << "Deleting 50...\n";
    tree.deleteKey(50);
    cout << "Inorder after deleting 50: ";
    tree.inorder();
    cout << endl;

    return 0;
}
