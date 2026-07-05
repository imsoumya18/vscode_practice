// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <sstream>
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int f(int idx, vector<int> &nums, vector<int> &dp)
{
    if (dp[idx] != -1)
        return dp[idx];

    int opt1 = f(idx - 1, nums, dp);
    int opt2 = f(idx - 2, nums, dp) + nums[idx];

    return dp[idx] = max(opt1, opt2);
}

int dp_rob(vector<int> &nums)
{
    int n = nums.size();
    int prev1 = nums[0], prev2 = 0, curr;

    for (int i = 1; i < n; i++)
    {
        curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    vector<int> vct1(nums.begin(), nums.end() - 1), vct2(nums.begin() + 1, nums.end());

    return max(dp_rob(vct1), dp_rob(vct2));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{2, 7, 9, 3, 1};

    cout << rob(nums) << endl;

    return 0;
}