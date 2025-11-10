#include <iostream>
using namespace std;

struct Product {
    int id;
    int quantity;
};

struct Node {
    Product data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* createNode(Product p) {
        Node* newNode = new Node;
        newNode->data = p;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    Node* insert(Node* node, Product p) {
        if (node == NULL)
            return createNode(p);

        if (p.id < node->data.id)
            node->left = insert(node->left, p);
        else if (p.id > node->data.id)
            node->right = insert(node->right, p);
        else {
            // if product already exists, update quantity
            node->data.quantity = p.quantity;
        }
        return node;
    }

    void insert(Product p) {
        root = insert(root, p);
    }

    Node* search(Node* node, int id) {
        if (node == NULL || node->data.id == id)
            return node;
        if (id < node->data.id)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << "Product ID: " << node->data.id
                 << ", Quantity: " << node->data.quantity << endl;
            inorder(node->right);
        }
    }

    void display() {
        if (root == NULL)
            cout << "Inventory is empty.\n";
        else
            inorder(root);
    }

    void findMaxQuantity(Node* node, int &maxQty, int &maxId) {
        if (node == NULL)
            return;

        if (node->data.quantity > maxQty) {
            maxQty = node->data.quantity;
            maxId = node->data.id;
        }

        findMaxQuantity(node->left, maxQty, maxId);
        findMaxQuantity(node->right, maxQty, maxId);
    }

    void getMaxQuantityProduct() {
        if (root == NULL) {
            cout << "Inventory is empty.\n";
            return;
        }

        int maxQty = -1, maxId = -1;
        findMaxQuantity(root, maxQty, maxId);
        cout << "Product with highest quantity:\n";
        cout << "Product ID: " << maxId << ", Quantity: " << maxQty << endl;
    }
};

int main() {
    BST inventory;
    int choice;

    do {
        cout << "\n=== Inventory Menu ===\n";
        cout << "1. Insert new product\n";
        cout << "2. Update product quantity\n";
        cout << "3. Search product by ID\n";
        cout << "4. Display all products\n";
        cout << "5. Show product with highest quantity\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Product p;
            cout << "Enter product ID: ";
            cin >> p.id;
            cout << "Enter quantity: ";
            cin >> p.quantity;
            inventory.insert(p);
            cout << "Product inserted successfully.\n";
        }
        else if (choice == 2) {
            int id, qty;
            cout << "Enter product ID to update: ";
            cin >> id;
            Node* found = inventory.search(inventory.root, id);
            if (found != NULL) {
                cout << "Enter new quantity: ";
                cin >> qty;
                found->data.quantity = qty;
                cout << "Quantity updated.\n";
            } else {
                cout << "Product not found.\n";
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter product ID to search: ";
            cin >> id;
            Node* found = inventory.search(inventory.root, id);
            if (found != NULL)
                cout << "Product found: ID " << found->data.id << ", Quantity " << found->data.quantity << endl;
            else
                cout << "Product not found.\n";
        }
        else if (choice == 4) {
            cout << "\nCurrent Inventory:\n";
            inventory.display();
        }
        else if (choice == 5) {
            inventory.getMaxQuantityProduct();
        }

    } while (choice != 0);

    cout << "Exiting program.\n";
    return 0;
}
