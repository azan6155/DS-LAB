#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

int countNodes(Node *root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void storeInorder(Node *root, int arr[], int &index) {
    if (!root) return;
    storeInorder(root->left, arr, index);
    arr[index++] = root->key;
    storeInorder(root->right, arr, index);
}

Node* buildAVL(int arr[], int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);
    root->left = buildAVL(arr, l, mid - 1);
    root->right = buildAVL(arr, mid + 1, r);
    return root;
}

Node* convertBSTtoAVL(Node *bstRoot) {
    int n = countNodes(bstRoot);
    int *arr = new int[n];
    int index = 0;
    storeInorder(bstRoot, arr, index);
    Node *avl = buildAVL(arr, 0, n - 1);
    delete[] arr;
    return avl;
}

Node* buildA() {
    Node *root = new Node(10);
    root->left = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    return root;
}

Node* buildB() {
    Node *root = new Node(10);
    root->right = new Node(16);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    return root;
}

void printInorder(Node *root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->key << " ";
    printInorder(root->right);
}

int main() {
    Node *a = buildA();
    Node *avlA = convertBSTtoAVL(a);

    cout << "AVL Tree from A (Inorder): ";
    printInorder(avlA);
    cout << endl;

    Node *b = buildB();
    Node *avlB = convertBSTtoAVL(b);

    cout << "AVL Tree from B (Inorder): ";
    printInorder(avlB);
    cout << endl;

    return 0;
}
