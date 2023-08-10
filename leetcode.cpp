// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> merged;

    for (int i = 0; i < intervals.size() - 1; i++)
        for (int j = i + 1; j < intervals.size(); j++)
            if (intervals[j][0] < intervals[i][0])
                swap(intervals[i], intervals[j]);

    for (auto i : intervals)
        if (merged.size() == 0)
            merged.push_back(i);
        else if (i[0] <= merged.back()[1])
        {
            vector<int> temp{merged.back()[0], max(merged.back()[1], i[1])};
            merged.pop_back();
            merged.push_back(temp);
        }
        else
            merged.push_back(i);

    return merged;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> intervals{{1, 4}, {4, 5}};

    for (auto i : intervals)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    cout << "----END----" << endl;

    vector<vector<int>>
        ans = merge(intervals);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}