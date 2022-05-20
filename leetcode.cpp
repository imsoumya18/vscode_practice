// @author Soumya
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<float>> val;
    vector<vector<int>> res;

    for (int i = 0; i < points.size(); i++)
    {
        vector<float> temp;
        temp.push_back(i);
        temp.push_back(sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]));
        val.push_back(temp);
    }

    for (int i = 0; i < val.size() - 1; i++)
        for (int j = 0; j < val.size() - i - 1; j++)
            if (val[j + 1][1] < val[j][1])
                swap(val[j], val[j + 1]);

    for (int i = 0; i < k; i++)
        res.push_back(points[val[i][0]]);

    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> points{{3, 3}, {5, -1}, {-2, 4}}, clop;
    int k = 2;

    clop = kClosest(points, k);

    for (auto i : clop)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}