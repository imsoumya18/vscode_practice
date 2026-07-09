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

int maximumSafenessFactor(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> manhattan(n, vector<int>(n, INT_MAX));
    queue<vector<int>> q; // {r, c, manhattan distance}

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
            {
                manhattan[i][j] = 0;
                q.push({i, j, 0});
            }

    vector<int> drow{-1, 0, 1, 0}, dcol{0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front()[0];
        int c = q.front()[1];
        int d = q.front()[2];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            int ndist = d + 1;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && ndist < manhattan[nrow][ncol])
            {
                manhattan[nrow][ncol] = ndist;
                q.push({nrow, ncol, ndist});
            }
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> maxHeap;
    maxHeap.push({manhattan[0][0], {0, 0}});
    vector<vector<int>> safeness(n, vector<int>(n, INT_MIN));
    safeness[0][0] = manhattan[0][0];

    while (!maxHeap.empty())
    {
        int score = maxHeap.top().first;
        int r = maxHeap.top().second.first;
        int c = maxHeap.top().second.second;
        maxHeap.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && min(score, manhattan[nrow][ncol]) > safeness[nrow][ncol])
            {
                safeness[nrow][ncol] = min(score, manhattan[nrow][ncol]);
                maxHeap.push({safeness[nrow][ncol], {nrow, ncol}});
            }
        }
    }

    return safeness[n - 1][n - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    cout << lengthOfLIS(nums) << endl;

    return 0;
}