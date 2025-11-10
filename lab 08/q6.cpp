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

// Count number of nodes in BST
int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Find median using inorder traversal
void findMedianUtil(Node* root, int& count, int n, double& median, Node*& prev) {
    if (root == NULL)
        return;

    findMedianUtil(root->left, count, n, median, prev);

    count++;

    // Odd number of nodes
    if (n % 2 == 1 && count == (n + 1) / 2)
        median = root->data;

    // Even number of nodes
    if (n % 2 == 0) {
        if (count == n / 2)
            prev = root;
        else if (count == n / 2 + 1)
            median = (prev->data + root->data) / 2.0;
    }

    findMedianUtil(root->right, count, n, median, prev);
}

double findMedian(Node* root) {
    int n = countNodes(root);
    double median = 0;
    int count = 0;
    Node* prev = NULL;
    findMedianUtil(root, count, n, median, prev);
    return median;
}

int main() {
    Node* root = NULL;

    // Example BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Median of BST is: " << findMedian(root) << endl;

    return 0;
}
