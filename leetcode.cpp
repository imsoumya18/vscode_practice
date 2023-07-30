// @author Soumya
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int ro = matrix.size(), col = matrix[0].size();
    vector<vector<int>> ans;

    for (int i = 0; i < col; i++)
    {
        vector<int> row;

        for (int j = 0; j < ro; j++)
        {
            row.push_back(matrix[j][i]);
        }

        ans.push_back(row);
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}};

    for (auto i : matrix)
    {
        for (auto j : i)
            cout << j << "  ";
        cout << endl;
    }

    for (auto i : transpose(matrix))
    {
        for (auto j : i)
            cout << j << "  ";
        cout << endl;
    }

    return 0;
}