// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int it, rowMin = 0, colMin = 0, rowMax = matrix.size() - 1, colMax = matrix[0].size() - 1;

    while (rowMin <= rowMax && colMin <= colMax)
    {
        for (it = colMin; it <= colMax; it++)
            res.push_back(matrix[rowMin][it]);
        rowMin++;

        for (it = rowMin; it <= rowMax; it++)
            res.push_back(matrix[it][colMax]);
        colMax--;

        if (rowMin <= rowMax)
        {
            for (it = colMax; it >= colMin; it--)
                res.push_back(matrix[rowMax][it]);
            rowMax--;
        }

        if (colMin <= colMax)
        {
            for (it = rowMax; it >= rowMin; it--)
                res.push_back(matrix[it][colMin]);
            colMin++;
        }
    }

    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> nums{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    for (auto i : nums)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    vector<int> ans = spiralOrder(nums);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}