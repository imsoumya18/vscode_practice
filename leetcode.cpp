// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void print1d(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";

    cout << endl;
}

void print2d(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

void rev(vector<int> &nums, int l, int r)
{
    while (l <= r)
    {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int l = n - 2, r = n - 1;

    while (l >= 0 && nums[l] >= nums[l + 1])
        l--;

    if (l >= 0)
    {
        while (r > l && nums[r] <= nums[l])
            r--;

        swap(nums[l], nums[r]);
    }

    l++;

    while (l < r)
    {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
