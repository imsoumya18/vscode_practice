// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
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

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int minCost(vector<int> &height)
{
    // Code here
    int n = height.size();

    int prev1 = 0;
    int prev2 = abs(height[1] - height[0]);
    int curr;

    for (int i = 1; i < n; i++)
    {
        int step1 = prev1 + abs(height[i] - height[i - 1]);
        int step2 = INT_MAX;
        if (i > 1)
            step2 = prev2 + abs(height[i] - height[i - 2]);

        curr = min(step1, step2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int help(int idx, vector<int> &height, vector<int> &dp)
{
    if (dp[idx] != -1)
        return dp[idx];

    int step1 = dp[idx - 1] + abs(height[idx] - height[idx - 1]);
    int step2 = INT_MAX;
    if (idx > 1)
        step2 = dp[idx - 2] + abs(height[idx] - height[idx - 2]);

    return dp[idx] = min(step1, step2);
}

int minCost(vector<int> &height)
{
    // Code here
    int n = height.size();

    vector<int> dp(n, -1);
    dp[0] = 0;

    return help(n - 1, height, dp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> arr{2, 3, 5, 7, 9};
    int k = 100;

    cout << checkSubsequenceSum(arr, k) << endl;

    return 0;
}