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

void selection_sort(vector<int> &vct)
{
    int n = vct.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (vct[j] < vct[i])
                swap(vct[i], vct[j]);
}

void bubble_sort(vector<int> &vct)
{
    int n = vct.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (vct[j + 1] < vct[j])
                swap(vct[j], vct[j + 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{5, 4, 3, 2, 1};

    print1d(vct);

    bubble_sort(vct);

    print1d(vct);

    return 0;
}
