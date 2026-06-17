// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

void print(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

bool possible(vector<int> &nums, int max_sum, int k)
{
    int no_of_divs = 1, curr_sum = 0;

    for (int i = 0; i < nums.size(); i++)
        if (curr_sum + nums[i] > max_sum)
        {
            no_of_divs++;
            curr_sum = nums[i];
        }
        else
            curr_sum += nums[i];

    if (no_of_divs > k)
        return false;

    return true;
}

int splitArray(vector<int> &nums, int k)
{
    // code here
    int n = nums.size();
    int lo = INT_MIN, hi = 0;

    for (auto page : nums)
    {
        lo = max(lo, page);
        hi += page;
    }

    int ans = -1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (possible(nums, mid, k))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}