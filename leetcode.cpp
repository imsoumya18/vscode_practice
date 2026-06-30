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

int numSubseq(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    const int mod = 1e9 + 7;
    vector<int> power(n + 1, 1);

    for (int i = 1; i <= n; i++)
        power[i] = (2LL * power[i - 1]) % mod;

    int ans = 0;
    int l = 0, r = n - 1;

    while (l <= r)
    {
        if (nums[l] + nums[r] <= target)
        {
            ans = (ans + power[r - l]) % mod;
            l++;
        }
        else
            r--;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{3, 3, 6, 8};
    int target = 10;

    cout << numSubseq(nums, target) << endl;

    return 0;
}