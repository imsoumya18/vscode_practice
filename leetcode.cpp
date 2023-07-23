// @author Soumya
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int l = 0, h = nums.size() - 1;
    int mid = (l + h) / 2;

    while (l < h)
    {
        if (nums[mid] >= nums[0])
            l = mid + 1;
        else
            h = mid;

        mid = (l + h) / 2;
    }

    if (l == nums.size() - 1 && nums[l] > nums[l - 1])
        l = 0;

    return nums[l];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{1};

    cout << findMin(nums) << endl;

    return 0;
}