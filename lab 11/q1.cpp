#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable
{
public:
    int bucketSize;
    vector<list<pair<string, string>>> table;

    HashTable(int size = 10)
    {
        bucketSize = size;
        table.resize(size);
    }

    int hashFunc(string s)
    {
        int sum = 0;
        for (char c : s)
            sum += c;
        return sum % bucketSize;
    }

    void insertValue(string key, string value)
    {
        int index = hashFunc(key);
        table[index].push_back({key, value});
    }

    void display()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            cout << i << ": ";
            for (auto &p : table[i])
                cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;
        }
    }
};

int main()
{
    HashTable myhash;

    myhash.insertValue("A", "aaaaa");
    myhash.insertValue("B", "bbbbb");
    myhash.insertValue("C", "ccccc");
    myhash.insertValue("A", "zzzzz");

    myhash.display();
}
