#include <iostream>
using namespace std;

void bubbleSortStrings(string words[], int size)
{
    for (int pass = 1; pass < size; pass++)
    {
        for (int k = 0; k < size - pass; k++)
        {
            if (words[k] > words[k + 1])
            {
                string temp = words[k];
                words[k] = words[k + 1];
                words[k + 1] = temp;
            }
        }
    }
}

int main()
{
    string fruits[5] = {"banana", "apple", "cherry", "date", "grape"};
    int count = 5;

    bubbleSortStrings(fruits, count);

    cout << "Fruits in alphabetical order: ";
    for (int i = 0; i < count; i++)
    {
        cout << fruits[i] << " ";
    }
    cout << "\n";

    return 0;
}
