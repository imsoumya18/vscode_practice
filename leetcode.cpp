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

int solve(int idx, int n, int canBuy, int canSell, vector<int> &prices,
          vector<vector<int>> &dp)
{
    if (idx == n || canBuy == 0)
        return 0;

    if (dp[idx][canBuy] != -1)
        return dp[idx][canBuy];

    int profit = 0;

    if (canBuy == canSell)
    {
        int buy = -prices[idx] + solve(idx + 1, n, canBuy - 1, canSell, prices, dp);
        int notBuy = solve(idx + 1, n, canBuy, canSell, prices, dp);

        profit = max(buy, notBuy);
    }
    else if (canBuy < canSell)
    {

        int sell = prices[idx] + solve(idx + 1, n, canBuy, canSell - 1, prices, dp);
        int notSell = solve(idx + 1, n, canBuy, canSell, prices, dp);

        profit = max(sell, notSell);
    }

    return dp[idx][canBuy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));

    return solve(0, n, 2, 2, prices, dp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}