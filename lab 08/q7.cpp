#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// Count nodes in range [a, b]
int countInRange(Node* root, int a, int b) {
    if (root == NULL)
        return 0;

    if (root->data >= a && root->data <= b)
        return 1 + countInRange(root->left, a, b) + countInRange(root->right, a, b);
    else if (root->data < a)
        return countInRange(root->right, a, b);
    else // root->data > b
        return countInRange(root->left, a, b);
}

int main() {
    Node* root = NULL;

    // Example BST
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 1);

    int a, b;
    cout << "Enter range a and b: ";
    cin >> a >> b;

    int count = countInRange(root, a, b);
    cout << "Number of nodes in range [" << a << ", " << b << "] = " << count << endl;

    return 0;
}
