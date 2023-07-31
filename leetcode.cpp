// @author Soumya
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    sort(nums.begin(), nums.end());
    int ans = 1, currlen = 1;

    for (int i = 1; i < nums.size(); i++)
        if (nums[i] == nums[i - 1])
            continue;
        else if (nums[i] == nums[i - 1] + 1)
        {
            currlen++;
            ans = max(ans, currlen);
        }
        else
            currlen = 1;

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{1, 0, 2, 1};

    cout << longestConsecutive(nums) << endl;

    return 0;
}