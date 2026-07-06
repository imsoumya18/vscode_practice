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

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
        for (int prev = 0; prev < 4; prev++)
            for (int task = 0; task < 3; task++)
                if (task != prev)
                    dp[day][prev] = max(dp[day][prev], points[day][task] + dp[day - 1][task]);

    return dp[n - 1][3];
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