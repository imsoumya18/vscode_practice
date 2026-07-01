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

void solve(vector<vector<char>> &board)
{
    int m = board.size(), n = board[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        if (board[i][0] == 'O')
        {
            board[i][0] = '1';
            q.push({i, 0});
        }

        if (board[i][n - 1] == 'O')
        {
            board[i][n - 1] = '1';
            q.push({i, n - 1});
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (board[0][i] == 'O')
        {
            board[0][i] = '1';
            q.push({0, i});
        }

        if (board[m - 1][i] == 'O')
        {
            board[m - 1][i] = '1';
            q.push({m - 1, i});
        }
    }

    vector<int> drow{-1, 0, 1, 0}, dcol{0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i], ncol = c + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O')
            {
                board[nrow][ncol] = '1';
                q.push({nrow, ncol});
            }
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == '1')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> image{{0, 0, 0}, {0, 0, 0}};
    int sr = 0, sc = 0, color = 0;

    print(image);

    cout << endl;

    print(floodFill(image, sr, sc, color));

    return 0;
}