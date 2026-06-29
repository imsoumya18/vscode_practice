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

bool possible(vector<int> &weights, int max_days, int capacity)
{
    int days_cnt = 1, curr_capacity = 0;

    for (auto w : weights)
    {
        if (curr_capacity + w > capacity)
        {
            days_cnt++;
            curr_capacity = w;
        }
        else
            curr_capacity += w;

        if (days_cnt > max_days)
            return false;
    }

    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int l = INT_MIN, r = 0;

    for (auto w : weights)
    {
        l = max(l, w);
        r += w;
    }

    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (possible(weights, days, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{9, 8, 7, 6, 5, 4, 3, 2, 1};

    print(vct);

    recursive_insertion_sort(vct, vct.size());

    print(vct);

    return 0;
}