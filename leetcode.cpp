// @author Soumya
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<float>> val;

    for (int i = 0; i < points.size(); i++)
    {
        vector<float> temp;
        temp.push_back(i);
        temp.push_back(sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]));
        val.push_back(temp);
    }

    for(i=0; i<val.size();i++)

    return points;
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

    return 0;
}