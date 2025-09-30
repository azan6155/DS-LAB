#include <iostream>
#include <vector>
using namespace std;

void sortSelection(vector<int> &nums)
{
    int len = nums.size();
    for (int pos = 0; pos < len - 1; pos++)
    {
        int minIdx = pos;
        for (int k = pos + 1; k < len; k++)
        {
            if (nums[k] < nums[minIdx])
            {
                minIdx = k;
            }
        }
        int temp = nums[pos];
        nums[pos] = nums[minIdx];
        nums[minIdx] = temp;
    }
}

bool hasDuplicates(vector<int> &nums)
{
    sortSelection(nums);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "Enter size of the array: ";
    int size;
    cin >> size;

    vector<int> numbers(size);
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    if (hasDuplicates(numbers))
        cout << "The array contains duplicates.\n";
    else
        cout << "The array does not contain duplicates.\n";

    return 0;
}
