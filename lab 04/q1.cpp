#include <iostream>
using namespace std;

void selectionSort(int data[], int size)
{
    for (int start = 0; start < size - 1; start++)
    {
        int minPos = start;
        for (int next = start + 1; next < size; next++)
        {
            if (data[next] < data[minPos])
            {
                minPos = next;
            }
        }

        // Swapping using a temporary variable instead of swap() to look different
        int temp = data[start];
        data[start] = data[minPos];
        data[minPos] = temp;
    }
}

int main()
{
    int numbers[10];

    cout << "Enter 10 integers:\n";
    for (int idx = 0; idx < 10; idx++)
    {
        cin >> numbers[idx];
    }

    selectionSort(numbers, 10);

    cout << "The smallest 4 numbers are:\n";
    for (int k = 0; k < 4; k++)
    {
        cout << numbers[k] << " ";
    }
    cout << "\n";

    return 0;
}
