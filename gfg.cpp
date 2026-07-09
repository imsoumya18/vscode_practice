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

int f(int idx, int prev, vector<vector<int>> points, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        int maxi = 0;

        for (int i = 0; i < 3; i++)
            if (i != prev)
                maxi = max(maxi, points[0][i]);

        return maxi;
    }

    if (dp[idx][prev] != -1)
        return dp[idx][prev];

    int maxi = 0;

    for (int i = 0; i < 3; i++)
        if (i != prev)
            maxi = max(maxi, points[idx][i] + f(idx - 1, i, points, dp));

    return dp[idx][prev] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));

    return f(n - 1, 3, points, dp);
}

void backtrack(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp, string curr, set<string> &results)
{
    if (idx1 == 0 || idx2 == 0)
    {
        results.insert(curr);
        return;
    }

    if (s1[idx1 - 1] == s2[idx2 - 1])
        backtrack(idx1 - 1, idx2 - 1, s1, s2, dp, s1[idx1 - 1] + curr, results);
    else
    {
        if (dp[idx1 - 1][idx2] >= dp[idx1][idx2 - 1])
            backtrack(idx1 - 1, idx2, s1, s2, dp, curr, results);

        if (dp[idx1][idx2 - 1] >= dp[idx1 - 1][idx2])
            backtrack(idx1, idx2 - 1, s1, s2, dp, curr, results);
    }
}

vector<string> allLCS(string &s1, string &s2)
{
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 0; i <= n1; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= n2; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    set<string> results;

    backtrack(n1, n2, s1, s2, dp, "", results);

    return vector<string>(results.begin(), results.end());
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

    vector<int> points {}

    return 0;
}