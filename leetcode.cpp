// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    vector<int> vct;

    for (auto i : Mat)
        for (auto j : i)
            vct.push_back(j);

    for (int i = 0; i < N * N - 1; i++)
        for (int j = i + 1; j < N * N; j++)
            if (vct[j] < vct[i])
                swap(vct[i], vct[j]);

    int idx = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            Mat[i][j] = vct[idx];
            idx++;
        }

    return Mat;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> Mat{{10, 20, 30, 40},
                            {15, 25, 35, 45},
                            {27, 29, 37, 48},
                            {32, 33, 39, 50}};

    for (auto i : Mat)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    cout << "---END---" << endl;

    for (auto i : sortedMatrix(4, Mat))
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}