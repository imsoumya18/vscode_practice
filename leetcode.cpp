// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i = n;

    while (nums[i] > nums[i - 1])
        i--;

    swap(nums[i], nums[i - 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{1, 2, 3};

    return 0;
}