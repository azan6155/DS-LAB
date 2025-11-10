#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Combatant {
    int id;
    string name;
    int hp;
    int attack;

    Combatant() {}
    Combatant(int i, string n, int h, int a) {
        id = i;
        name = n;
        hp = h;
        attack = a;
    }
};

struct Node {
    Combatant data;
    Node* left;
    Node* right;

    Node(Combatant c) {
        data = c;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, Combatant c) {
        if (node == nullptr)
            return new Node(c);
        if (c.id < node->data.id)
            node->left = insert(node->left, c);
        else if (c.id > node->data.id)
            node->right = insert(node->right, c);
        return node;
    }

    void insert(Combatant c) {
        root = insert(root, c);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int id) {
        if (root == nullptr)
            return root;
        if (id < root->data.id)
            root->left = deleteNode(root->left, id);
        else if (id > root->data.id)
            root->right = deleteNode(root->right, id);
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
            root->right = deleteNode(root->right, temp->data.id);
        }
        return root;
    }

    void deleteByID(int id) {
        root = deleteNode(root, id);
    }

    bool isEmpty() {
        return root == nullptr;
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data.name << " (HP:" << root->data.hp << ") ";
            inorder(root->right);
        }
    }

    void showTeam(string teamName) {
        cout << teamName << " team: ";
        inorder(root);
        cout << endl;
    }

    Node* frontline() {
        return minValueNode(root);
    }
};

int randomDamage(int base) {
    return base + (rand() % 5);
}

void printLine() {
    cout << "-------------------------------------------" << endl;
}

int main() {
    srand(time(0));

    BST heroes, enemies;

    heroes.insert(Combatant(10, "Aragon", 40, 10));
    heroes.insert(Combatant(20, "Luna", 35, 12));
    heroes.insert(Combatant(30, "Gorath", 50, 8));
    heroes.insert(Combatant(40, "Mira", 30, 15));
    heroes.insert(Combatant(50, "Thorn", 45, 11));

    enemies.insert(Combatant(15, "Goblin", 25, 9));
    enemies.insert(Combatant(25, "Orc", 35, 10));
    enemies.insert(Combatant(35, "Troll", 45, 8));
    enemies.insert(Combatant(45, "Vampire", 40, 12));
    enemies.insert(Combatant(55, "Dragon", 60, 14));

    int round = 1;

    cout << "Welcome to BattleQuest: BST Arena" << endl;
    cout << "Heroes vs Enemies" << endl;
    printLine();

    while (!heroes.isEmpty() && !enemies.isEmpty()) {
        cout << "Round " << round++ << endl;
        heroes.showTeam("Heroes");
        enemies.showTeam("Enemies");
        printLine();

        Node* hero = heroes.frontline();
        Node* enemy = enemies.frontline();

        if (!hero || !enemy) break;

        cout << hero->data.name << " attacks " << enemy->data.name << endl;
        int dmg = randomDamage(hero->data.attack);
        enemy->data.hp -= dmg;
        cout << "Damage dealt: " << dmg << endl;
        if (enemy->data.hp <= 0) {
            cout << enemy->data.name << " has been defeated" << endl;
            enemies.deleteByID(enemy->data.id);
        } else {
            cout << enemy->data.name << " HP now: " << enemy->data.hp << endl;
        }

        if (enemies.isEmpty()) break;

        hero = heroes.frontline();
        enemy = enemies.frontline();

        cout << enemy->data.name << " attacks " << hero->data.name << endl;
        int edmg = randomDamage(enemy->data.attack);
        hero->data.hp -= edmg;
        cout << "Damage dealt: " << edmg << endl;
        if (hero->data.hp <= 0) {
            cout << hero->data.name << " has been defeated" << endl;
            heroes.deleteByID(hero->data.id);
        } else {
            cout << hero->data.name << " HP now: " << hero->data.hp << endl;
        }

        printLine();
    }

    if (heroes.isEmpty())
        cout << "All heroes are defeated. Enemies win." << endl;
    else
        cout << "Enemies are defeated. Heroes win!" << endl;

    printLine();
    cout << "Game Over" << endl;
    return 0;
}
