#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
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

int binarySearch(vector<int> &arr, int target)
{
    selectionSort(arr);
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {20, 12, 15, 2, 10, 1, 13, 9, 25};

    int rollNumber;
    cout << "Enter the last two digits of your roll number: ";
    cin >> rollNumber;

    int index = binarySearch(arr, rollNumber);

    if (index == -1)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found at position : " << index + 1 << endl;
    }

    return 0;
}
