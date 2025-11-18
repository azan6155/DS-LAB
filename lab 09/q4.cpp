#include <iostream>
using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int h(Node *n) { return n ? n->height : 0; }

int balanceFactor(Node *n) { return n ? h(n->left) - h(n->right) : 0; }

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;

    return x;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;

    return y;
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
    int bf = balanceFactor(root);

    // LL Case
    if (bf > 1 && key < root->left->key)
        return rotateRight(root);

    // RR Case
    if (bf < -1 && key > root->right->key)
        return rotateLeft(root);

    // LR Case
    if (bf > 1 && key > root->left->key)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL Case
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
    Node *root = NULL;
    int arr[] = {10, 5, 15, 3, 7};
    for (int x : arr)
        root = insert(root, x);

    root = insert(root, 12);

    inorder(root);
    cout << endl;
}
