#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Dictionary
{
public:
    vector<list<pair<string, string>>> table;

    Dictionary() { table.resize(100); }

    int hashFunc(string s)
    {
        int sum = 0;
        for (char c : s)
            sum += c;
        return sum % 100;
    }

    void Add_Record(string key, string value)
    {
        int index = hashFunc(key);
        table[index].push_back({key, value});
    }

    void Word_Search(string key)
    {
        int index = hashFunc(key);
        for (auto &p : table[index])
        {
            if (p.first == key)
            {
                cout << "Found: (" << p.first << ", " << p.second << ")\n";
                return;
            }
        }
        cout << "Error: Word not found!\n";
    }

    void Print_Dictionary()
    {
        for (int i = 0; i < 100; i++)
        {
            if (!table[i].empty())
            {
                cout << "index " << i << ": ";
                for (auto &p : table[i])
                    cout << "(" << p.first << ", " << p.second << ") ";
                cout << endl;
            }
        }
    }
};

int main()
{
    Dictionary d;

    d.Add_Record("AB", "FASTNU");
    d.Add_Record("CD", "CS");
    d.Word_Search("AB");

    d.Print_Dictionary();
}
