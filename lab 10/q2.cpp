#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthLargest(vector<int> arr, int k)
{
    priority_queue<int> maxHeap;

    for (int x : arr)
        maxHeap.push(x);

    for (int i = 1; i < k; i++)
        maxHeap.pop();

    return maxHeap.top();
}

int main()
{
    vector<int> arr1 = {1, 23, 12, 9, 30, 2, 50};
    int k1 = 3;
    cout << "3rd largest: " << kthLargest(arr1, k1) << endl;

    vector<int> arr2 = {12, 3, 5, 7, 19};
    int k2 = 2;
    cout << "2nd largest: " << kthLargest(arr2, k2) << endl;

    return 0;
}
