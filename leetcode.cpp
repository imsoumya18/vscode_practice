// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
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

bool possible(vector<int> weights, int capacity, int days)
{
    int req_days = 0, weight = 0;

    for (auto w : weights)
    {
        if (w > capacity)
            return false;

        if (weight + w > capacity)
        {
            req_days++;
            weight = w;
        }
        else
            weight += w;
    }
    req_days++;

    return req_days <= days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int lo = INT_MAX, hi = 0, ans = -1;

    for (auto w : weights)
    {
        lo = min(lo, w);
        hi += w;
    }

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (possible(weights, mid, days))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> weights{1, 2, 3, 1, 1};
    int days = 4;

    cout << shipWithinDays(weights, days) << endl;

    return 0;
}