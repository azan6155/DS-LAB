#include <iostream>
using namespace std;

void selectionSort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
}

int linearSearch(string arr[], int n, const string &target)
{
    int steps = 0;
    for (int i = 0; i < n; i++)
    {
        steps++;
        if (arr[i] == target)
        {
            cout << "Linear Search Steps: " << steps << endl;
            return i;
        }
    }
    cout << "Linear Search Steps: " << steps << endl;
    return -1;
}

int binarySearch(string arr[], int n, const string &target)
{
    int start = 0, end = n - 1;
    int steps = 0;
    while (start <= end)
    {
        steps++;
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            cout << "Binary Search Steps: " << steps << endl;
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << "Binary Search Steps: " << steps << endl;
    return -1;
}

int main()
{
    string arr[] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"};
    int n = 10;

    selectionSort(arr, n);

    string names[] = {"Aftab", "Rizwan", "Tariq"};

    for (const string &name : names)
    {
        cout << "\nSearching for: " << name << endl;

        int linearResult = linearSearch(arr, n, name);
        if (linearResult != -1)
        {
            cout << "Linear Search - " << name << " found at index: " << linearResult << endl;
        }
        else
        {
            cout << "Linear Search - " << name << " not found." << endl;
        }

        int binaryResult = binarySearch(arr, n, name);
        if (binaryResult != -1)
        {
            cout << "Binary Search - " << name << " found at index: " << binaryResult << endl;
        }
        else
        {
            cout << "Binary Search - " << name << " not found." << endl;
        }
    }

    return 0;
}
