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

static bool comp(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), comp);

    vector<vector<int>> result{intervals[0]};

    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> last = result.back();

        if (intervals[i][0] <= last[1])
            last[1] = max(last[1], intervals[i][1]);
        else
            result.push_back(intervals[i]);
    }

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> bt{4, 3, 7, 1, 2};

    cout << solve(bt) << endl;

    return 0;
}