// @author Soumya
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> vct(m, vector<int>(n, 0));

    vct[m - 1][n - 1] = 1;

    for (int i = 0; i < m - 1; i++)
        vct[i][n - 1] = 1;

    for (int j = 0; j < n - 1; j++)
        vct[m - 1][j] = 1;

    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
            vct[i][j] = vct[i][j + 1] + vct[i + 1][j];

    // for (auto i : vct)
    // {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }

    return vct[0][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m = 1, n = 1;

    cout << uniquePaths(m, n) << endl;

    return 0;
}