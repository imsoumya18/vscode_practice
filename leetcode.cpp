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

int isPossible(int idx, vector<int> &nums, int target,
               vector<vector<int>> &dp)
{
    if (target < 0)
        return 0;

    if (idx == nums.size())
        return target == 0;

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int take = isPossible(idx + 1, nums, target - nums[idx], dp);
    int notTake = isPossible(idx + 1, nums, target, dp);

    return dp[idx][target] = (take + notTake) % (1e9 + 7);
}

int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));

    return isPossible(0, arr, k, dp);
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