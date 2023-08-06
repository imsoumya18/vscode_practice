// @author Soumya
#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool canSplitArray(vector<int> &nums, int m)
{
    int n = nums.size();

    if (n == 1 || n == 2)
        return true;

    bool ans = false;

    for (int i = 0; i < n - 1; i++)
        if (nums[i] + nums[i + 1] >= m)
            ans = true;

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums{2, 1, 1, 3};
    int m = 4;

    cout << canSplitArray(nums, m) << endl;

    return 0;
}