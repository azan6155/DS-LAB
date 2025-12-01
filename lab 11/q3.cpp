#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Hash
{
public:
    vector<list<int>> table;

    Hash(int size = 10)
    {
        table.resize(size);
    }

    int hashFunc(int key)
    {
        return key % table.size();
    }

    void insertItem(int key)
    {
        table[hashFunc(key)].push_back(key);
    }

    void deleteItem(int key)
    {
        int index = hashFunc(key);
        table[index].remove(key);
    }

    bool searchItem(int key)
    {
        int index = hashFunc(key);
        for (int x : table[index])
            if (x == key)
                return true;
        return false;
    }

    void display()
    {
        for (int i = 0; i < table.size(); i++)
        {
            cout << i << ": ";
            for (int x : table[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main()
{
    Hash h;
    h.insertItem(15);
    h.insertItem(25);
    h.insertItem(35);

    h.display();
}
