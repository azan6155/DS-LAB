#include <iostream>
using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int h(Node *n) { return n ? n->height : 0; }

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));
    return y;
}

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));
    return x;
}

Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    root->height = 1 + max(h(root->left), h(root->right));
    int bf = h(root->left) - h(root->right);

    if (bf > 1 && key < root->left->key)
        return rotateRight(root);
    if (bf < -1 && key > root->right->key)
        return rotateLeft(root);
    if (bf > 1 && key > root->left->key)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bf < -1 && key < root->right->key)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main()
{
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    Node *root = NULL;
    for (int x : arr)
        root = insert(root, x);
    root = insert(root, 55);
    root = rotateLeft(root);
    inorder(root);
}
