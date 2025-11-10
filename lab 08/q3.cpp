#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
    Node(Student s) {
        data = s;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, Student s) {
        if (node == nullptr)
            return new Node(s);

        if (s.name < node->data.name)
            node->left = insert(node->left, s);
        else if (s.name > node->data.name)
            node->right = insert(node->right, s);
        return node;
    }

    void insert(Student s) {
        root = insert(root, s);
    }

    Node* search(Node* node, string name) {
        if (node == nullptr || node->data.name == name)
            return node;
        if (name < node->data.name)
            return search(node->left, name);
        else
            return search(node->right, name);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, string name) {
        if (root == nullptr) return root;

        if (name < root->data.name)
            root->left = deleteNode(root->left, name);
        else if (name > root->data.name)
            root->right = deleteNode(root->right, name);
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
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data.name);
        }
        return root;
    }

    void deleteByName(string name) {
        root = deleteNode(root, name);
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << "Name: " << root->data.name
                 << ", Roll: " << root->data.roll
                 << ", Score: " << root->data.score << endl;
            inorder(root->right);
        }
    }

    void display() {
        if (root == nullptr)
            cout << "Tree is empty.\n";
        else
            inorder(root);
    }

    // Delete all students whose score < 10
    Node* deleteLowScore(Node* root) {
        if (root == nullptr) return nullptr;
        root->left = deleteLowScore(root->left);
        root->right = deleteLowScore(root->right);

        if (root->data.score < 10) {
            cout << "Deleting " << root->data.name << " (Score: " << root->data.score << ")" << endl;
            root = deleteNode(root, root->data.name);
        }
        return root;
    }

    void deleteLowScore() {
        root = deleteLowScore(root);
    }

    // Find student with maximum score
    void findMaxScore(Node* root, Student &maxStudent) {
        if (root == nullptr) return;
        if (root->data.score > maxStudent.score)
            maxStudent = root->data;
        findMaxScore(root->left, maxStudent);
        findMaxScore(root->right, maxStudent);
    }

    Student getMaxScoreStudent() {
        Student maxStudent = {"None", -1, -1};
        findMaxScore(root, maxStudent);
        return maxStudent;
    }
};

int main() {
    srand(time(0));

    Student arr[10] = {
        {"Alice", 1, 25},
        {"Bob", 2, 9},
        {"Charlie", 3, 14},
        {"David", 4, 30},
        {"Eva", 5, 7},
        {"Frank", 6, 20},
        {"Grace", 7, 5},
        {"Hannah", 8, 40},
        {"Ivan", 9, 17},
        {"Julia", 10, 28}
    };

    BST tree;

    cout << "Inserting 7 random students into BST...\n";
    bool used[10] = {false};
    for (int i = 0; i < 7; ) {
        int index = rand() % 10;
        if (!used[index]) {
            tree.insert(arr[index]);
            used[index] = true;
            cout << "Inserted: " << arr[index].name << endl;
            i++;
        }
    }

    cout << "\nAll students in BST (inorder traversal):\n";
    tree.display();

    cout << "\nEnter student name to search: ";
    string searchName;
    cin >> searchName;

    Node* found = tree.search(tree.root, searchName);
    if (found)
        cout << "Found: " << found->data.name << " (Roll: " << found->data.roll << ", Score: " << found->data.score << ")\n";
    else
        cout << "Student not found.\n";

    cout << "\nDeleting students with score less than 10...\n";
    tree.deleteLowScore();

    cout << "\nRemaining students in BST:\n";
    tree.display();

    cout << "\nFinding student with maximum score...\n";
    Student top = tree.getMaxScoreStudent();
    if (top.roll != -1)
        cout << "Top Scorer: " << top.name << " (Roll: " << top.roll << ", Score: " << top.score << ")\n";
    else
        cout << "Tree is empty.\n";

    return 0;
}
