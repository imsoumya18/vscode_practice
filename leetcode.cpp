// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void merge(vector<int> &nums, int l, int mid, int r)
{
    vector<int> v1, v2;

    for (int i = l; i <= mid; i++)
        v1.push_back(nums[i]);

    for (int i = mid + 1; i <= r; i++)
        v2.push_back(nums[i]);

    int i = l, j = 0, k = 0;

    while (j < v1.size() && k < v2.size())
    {
        if (v1[j] < v2[k])
        {
            nums[i] = v1[j];
            j++;
        }
        else
        {
            nums[i] = v2[k];
            k++;
        }
        i++;
    }

    while (j < v1.size())
    {
        nums[i] = v1[j];
        i++;
        j++;
    }

    while (k < v2.size())
    {
        nums[i] = v2[k];
        i++;
        k++;
    }
}

void merge_sort(vector<int> &nums, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);

        merge(nums, l, mid, r);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (auto i : nums)
        cout << i << " ";

    cout << endl;

    merge_sort(nums, 0, nums.size() - 1);

    for (auto i : nums)
        cout << i << " ";

    return 0;
}