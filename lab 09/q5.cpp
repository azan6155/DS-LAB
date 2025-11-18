#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int h(Node *n) { return n ? n->height : 0; }

int balanceFactor(Node *n) { return h(n->left) - h(n->right); }

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));
    return x;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));
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

void storeInorder(Node *root, vector<int> &v)
{
    if (!root)
        return;
    storeInorder(root->left, v);
    v.push_back(root->key);
    storeInorder(root->right, v);
}

int kthSmallest(Node *root, int k)
{
    vector<int> v;
    storeInorder(root, v);
    return v[k - 1];
}

int kthLargest(Node *root, int k)
{
    vector<int> v;
    storeInorder(root, v);
    return v[v.size() - k];
}

int main()
{
    Node *root = NULL;
    int arr[] = {10, 5, 15, 3, 7, 12};
    for (int x : arr)
        root = insert(root, x);

    int k = 2;

    cout << "kth Smallest: " << kthSmallest(root, k) << endl;
    cout << "kth Largest: " << kthLargest(root, k) << endl;

    cout << "Left Height: " << h(root->left) << endl;
    cout << "Right Height: " << h(root->right) << endl;

    return 0;
}
