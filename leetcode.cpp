// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <sstream>
#include <set>
#include <unordered_set>
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool solve(int idx1, int idx2, string &s, string &p, vector<vector<int>> &dp)
{
    if (idx1 < 0 && idx2 < 0)
        return true;

    if (idx2 < 0)
        return false;

    if (idx1 < 0)
    {
        for (int i = 0; i <= idx2; i++)
            if (p[i] != '*')
                return false;

        return true;
    }

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (s[idx1] == p[idx2] || p[idx2] == '?')
        return dp[idx1][idx2] = solve(idx1 - 1, idx2 - 1, s, p, dp);

    if (p[idx2] == '*')
        return dp[idx1][idx2] = solve(idx1 - 1, idx2, s, p, dp) || solve(idx1, idx2 - 1, s, p, dp);

    return false;
}

bool isMatch(string s, string p)
{
    int n1 = s.size(), n2 = p.size();
    vector<bool> prev(n2 + 1, false), curr(n2 + 1, false);

    prev[0] = true;

    for (int i = 1; i <= n2; i++)
    {
        if (p[i - 1] != '*')
            break;

        prev[i] = true;
    }

    for (int idx1 = 1; idx1 <= n1; idx1++)
    {
        curr[0] = false;

        for (int idx2 = 1; idx2 <= n2; idx2++)
            if (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '?')
                curr[idx2] = prev[idx2 - 1];
            else if (p[idx2 - 1] == '*')
                curr[idx2] = prev[idx2] || curr[idx2 - 1];
            else
                curr[idx2] = false;

        prev = curr;
    }

    return prev[n2];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}