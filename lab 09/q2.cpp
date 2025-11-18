#include <iostream>
using namespace std;

struct Node
{
    int key, height;
    Node *left;
    Node *right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int h(Node *n) { return n ? n->height : 0; }

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;
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

    root->height = max(h(root->left), h(root->right)) + 1;
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

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 15);
}
