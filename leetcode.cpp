// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void print1d(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";

    cout << endl;
}

void print2d(vector<vector<int>> vct)
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
    vector<vector<int>> vct;

    vector<int> last = intervals[0];

    for (int i = 1; i < intervals.size(); i++)
        if (intervals[i][0] <= last[1])
            last[1] = max(last[1], intervals[i][1]);
        else
        {
            vct.push_back(last);
            last = intervals[i];
        }

    vct.push_back(last);

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> spiral = spiralOrder(matrix);

    print1d(spiral);

    return 0;
}
