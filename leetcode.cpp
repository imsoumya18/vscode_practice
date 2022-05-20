// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<pair<int, pair<int, int>>> v;
    vector<vector<int>> res;

    for (auto i : points)
    {
        int x = i[0] * i[0] + i[1] * i[1];
        v.push_back({x, {i[0], i[1]}});
    }

    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - i - 1; j++)
            if (v[j + 1].first < v[j].first)
                swap(v[j], v[j + 1]);
    
    for(int i=0; i<k;i++){
        vector<int> temp;
        temp.push_back(v[i].second.first);
        temp.push_back(v[i].second.second);
        res.push_back(temp);
        temp.clear();
    }

    return res;
}

// vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
// {
//     vector<vector<int>> val;
//     vector<vector<int>> res;

//     for (int i = 0; i < points.size(); i++)
//     {
//         vector<int> temp;
//         temp.push_back(i);
//         temp.push_back(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
//         val.push_back(temp);
//     }

//     for (int i = 0; i < val.size() - 1; i++)
//         for (int j = 0; j < val.size() - i - 1; j++)
//             if (val[j + 1][1] < val[j][1])
//                 swap(val[j], val[j + 1]);

//     val.erase(1, 2);

//     return val;
// }

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