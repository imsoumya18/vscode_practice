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

int celebrity(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    int top = 0, bottom = n - 1;

    while (top < bottom)
    {
        if (mat[top][bottom] == 1)
            top++;
        else
            bottom--;
    }

    int idx = top;

    for (int i = 0; i < n; i++)
    {
        if (i != idx && mat[idx][i] == 1)
            return -1;

        if (i != idx && mat[i][idx] == 0)
            return -1;
    }

    return idx;
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