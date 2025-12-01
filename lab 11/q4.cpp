#include <iostream>
#include <unordered_map>
using namespace std;

struct Pair
{
    int a, b;
};

void findPairs(int arr[], int n)
{
    unordered_map<int, Pair> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if (mp.find(sum) != mp.end())
            {
                Pair p = mp[sum];
                if (p.a != arr[i] && p.b != arr[j] &&
                    p.a != arr[j] && p.b != arr[i])
                {
                    cout << "(" << p.a << "," << p.b << ") and (" << arr[i] << "," << arr[j] << ")";
                    return;
                }
            }
            mp[sum] = {arr[i], arr[j]};
        }
    }
    cout << "No pairs found";
}

int main()
{
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    findPairs(arr, 7);
    return 0;
}
