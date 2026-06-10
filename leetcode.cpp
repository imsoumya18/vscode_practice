// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
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

bool canJump(vector<int> &nums)
{
    int maxi = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (maxi < i)
            return false;

        maxi = max(maxi, i + nums[i]);
    }

    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}