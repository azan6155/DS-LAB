#include <iostream>
#include <vector>
using namespace std;

bool isHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] > arr[left])
            return false;
        if (right < n && arr[i] > arr[right])
            return false;
    }
    return true;
}

void heapify(vector<int> &heap, int i)
{
    int n = heap.size();
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapify(heap, smallest);
    }
}

void buildHeap(vector<int> &arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, i);
}

vector<int> heapSort(vector<int> arr)
{
    buildHeap(arr);
    vector<int> sorted;

    while (!arr.empty())
    {
        sorted.push_back(arr[0]);
        arr[0] = arr.back();
        arr.pop_back();
        heapify(arr, 0);
    }
    return sorted;
}

int main()
{
    vector<int> arr = {8, 7, 6, 5, 4};

    cout << "Is Heap? " << (isHeap(arr) ? "Yes" : "No") << endl;

    vector<int> sorted = heapSort(arr);
    cout << "Sorted: ";
    for (int x : sorted)
        cout << x << " ";

    return 0;
}
