// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int partition(vector<int> &nums, int l, int r)
{
    int pivot = nums[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
        if (nums[j] < pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }

    swap(nums[i + 1], nums[r]);
    return i + 1;
}

void quick_sort(vector<int> &nums, int l, int r)
{
    if (l < r)
    {
        int pi = partition(nums, l, r);

        quick_sort(nums, l, pi - 1);
        quick_sort(nums, pi + 1, r);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Unsorted Array: ";
    for (auto i : nums)
        cout << i << " ";

    cout << endl
         << "Sorted Array:   ";

    quick_sort(nums, 0, nums.size() - 1);

    for (auto i : nums)
        cout << i << " ";

    return 0;
}