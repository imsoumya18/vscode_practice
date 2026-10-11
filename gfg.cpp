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

bool invite(int boy, vector<vector<int>> &grid, vector<int> &checked, vector<int> &girlInvitedBy)
{
    for (int i = 0; i < grid[boy].size(); i++)
        if (grid[boy][i] && !checked[i])
        {
            checked[i] = 1;

            if (girlInvitedBy[i] == -1 || invite(girlInvitedBy[i], grid, checked, girlInvitedBy))
            {
                girlInvitedBy[i] = boy;
                return true;
            }
        }

    return false;
}

int maximumInvitations(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int maxInvites = 0;
    vector<int> girlInvitedBy(n, -1);

    for (int i = 0; i < m; i++)
    {
        vector<int> checked(n, 0);
        if (invite(i, grid, checked, girlInvitedBy))
            maxInvites++;
    }

    return maxInvites;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    print(primeFactors(13));

    return 0;
}