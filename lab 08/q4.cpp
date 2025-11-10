#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll;
    int score;
};

struct Node {
    Student data;
    Node* left;
    Node* right;
};

Node* createNode(Student s) {
    Node* newNode = new Node;
    newNode->data = s;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, Student s) {
    if (root == NULL)
        return createNode(s);

    if (s.name < root->data.name)
        root->left = insert(root->left, s);
    else if (s.name > root->data.name)
        root->right = insert(root->right, s);

    return root;
}

Node* search(Node* root, string name) {
    if (root == NULL || root->data.name == name)
        return root;
    if (name < root->data.name)
        return search(root->left, name);
    else
        return search(root->right, name);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << "Name: " << root->data.name
             << ", Roll: " << root->data.roll
             << ", Score: " << root->data.score << endl;
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    Student s1 = {"Alice", 1, 25};
    Student s2 = {"Bob", 2, 9};
    Student s3 = {"Charlie", 3, 14};
    Student s4 = {"David", 4, 30};
    Student s5 = {"Eva", 5, 7};
    Student s6 = {"Frank", 6, 20};
    Student s7 = {"Grace", 7, 15};

    root = insert(root, s1);
    root = insert(root, s2);
    root = insert(root, s3);
    root = insert(root, s4);
    root = insert(root, s5);
    root = insert(root, s6);
    root = insert(root, s7);

    cout << "Current BST (inorder traversal):" << endl;
    inorder(root);

    cout << "\nEnter student name to search or insert: ";
    string name;
    cin >> name;

    Node* found = search(root, name);

    if (found != NULL) {
        cout << "Student found!" << endl;
        cout << "Name: " << found->data.name
             << ", Roll: " << found->data.roll
             << ", Score: " << found->data.score << endl;
    } else {
        cout << "Student not found. Enter details to insert:" << endl;
        Student newStu;
        newStu.name = name;
        cout << "Enter roll number: ";
        cin >> newStu.roll;
        cout << "Enter score: ";
        cin >> newStu.score;

        root = insert(root, newStu);

        cout << "\nNew BST (inorder traversal):" << endl;
        inorder(root);
    }

    return 0;
}
