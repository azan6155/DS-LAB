#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    void heapify(int i)
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
            heapify(smallest);
        }
    }

    void buildHeap(vector<int> arr)
    {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--)
            heapify(i);
    }

    void update_key(int i, int new_val)
    {
        heap[i] = new_val;
        while (i != 0 && heap[(i - 1) / 2] > heap[i])
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        heapify(i);
    }

    void delete_key(int i)
    {
        heap[i] = heap.back();
        heap.pop_back();
        heapify(i);
    }

    void print()
    {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    MinHeap h;
    vector<int> arr = {8, 7, 6, 5, 4};
    h.buildHeap(arr);

    cout << "Initial Heap: ";
    h.print();

    h.update_key(2, 1);
    cout << "After update: ";
    h.print();

    h.delete_key(1);
    cout << "After delete: ";
    h.print();

    return 0;
}
