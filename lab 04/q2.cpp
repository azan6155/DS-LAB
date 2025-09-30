#include <iostream>
using namespace std;

void insertionSort(int nums[], int length, int start)
{
    for (int i = start + 1; i < length; i++)
    {
        int key = nums[i];
        int j = i - 1;

        // shift elements to the right
        while (j >= start && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void adjustArray(int nums[], int length)
{
    // Sort the whole array first
    insertionSort(nums, length, 0);

    int mid = length / 2;
    int last = length - 1;

    // Move the maximum element to the middle
    int temp = nums[mid];
    nums[mid] = nums[last];
    nums[last] = temp;

    // Sort the right side again after moving the max element
    insertionSort(nums, length, mid + 1);
}

int main()
{
    int data[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};

    adjustArray(data, 9);

    cout << "Array after adjustment (max element moved to middle):\n";
    for (int i = 0; i < 9; i++)
    {
        cout << data[i] << " ";
    }
    cout << "\n";

    return 0;
}
