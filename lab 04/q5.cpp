#include <iostream>
#include <vector>
using namespace std;

void sortSelection(vector<int> &nums)
{
    int len = nums.size();
    for (int p = 0; p < len - 1; p++)
    {
        int minPos = p;
        for (int q = p + 1; q < len; q++)
        {
            if (nums[q] < nums[minPos])
            {
                minPos = q;
            }
        }
        int temp = nums[p];
        nums[p] = nums[minPos];
        nums[minPos] = temp;
    }
}

int main()
{
    vector<int> years = {2022, 2023, 2024, 2022, 2023, 2024};

    sortSelection(years);

    cout << "Sorted array: ";
    for (int i = 0; i < years.size(); i++)
    {
        cout << years[i] << " ";
    }
    cout << "\n";

    return 0;
}

