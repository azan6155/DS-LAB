#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    int roll;
    string name;
    bool used;

    Student() { used = false; }
};

class StudentHashTable
{
public:
    vector<Student> table;

    StudentHashTable() { table.resize(15); }

    int hashFunc(int roll) { return roll % 15; }

    void InsertRecord(int roll, string name)
    {
        int index = hashFunc(roll);
        int attempt = 0;

        while (table[(index + attempt * attempt) % 15].used)
        {
            attempt++;
        }
        int finalIndex = (index + attempt * attempt) % 15;
        table[finalIndex].roll = roll;
        table[finalIndex].name = name;
        table[finalIndex].used = true;
    }

    void SearchRecord(int roll)
    {
        int index = hashFunc(roll);
        int attempt = 0;

        while (attempt < 15)
        {
            int finalIndex = (index + attempt * attempt) % 15;
            if (table[finalIndex].used && table[finalIndex].roll == roll)
            {
                cout << "Found: " << table[finalIndex].name << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found\n";
    }
};

int main()
{
    StudentHashTable s;

    s.InsertRecord(101, "Ali");
    s.InsertRecord(116, "Hassan");
    s.InsertRecord(131, "Zain");

    s.SearchRecord(116);
    s.SearchRecord(999);

    return 0;
}
