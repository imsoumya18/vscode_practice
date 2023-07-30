// @author Soumya
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool search(vector<vector<int>> matrix, int n, int m, int target)
{
    int lo = 0, hi = n - 1;
    int midrow = (lo + hi) / 2;

    while (lo <= hi)
    {
        if ((midrow == n - 1) || (matrix[midrow][0] <= target && matrix[midrow+1][0] > target))
            break;

        else if (matrix[midrow][0] > target)
            hi = midrow - 1;

        else
            lo = midrow + 1;

        midrow = (lo + hi) / 2;
    }

    lo = 0;
    hi = m - 1;
    int midcol = (lo + hi) / 2;

    while (lo <= hi)
    {
        if (matrix[midrow][midcol] == target)
            return true;

        else if (matrix[midrow][midcol] > target)
            hi = midcol - 1;

        else
            lo = midcol + 1;

        midcol = (lo + hi) / 2;
    }

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> matrix{
        {3, 4, 5, 13, 13, 15, 15, 24, 30, 31},
        {13, 14, 19, 19, 27, 31, 32, 33, 35, 62},
        {14, 23, 24, 25, 36, 37, 38, 44, 44, 63},
        {30, 34, 36, 38, 40, 42, 43, 47, 55, 65},
        {36, 39, 40, 41, 42, 51, 51, 58, 59, 69},
        {43, 44, 44, 49, 56, 59, 64, 64, 75, 82},
        {46, 46, 47, 63, 64, 66, 67, 70, 85, 89},
        {54, 57, 58, 65, 67, 70, 74, 88, 88, 93},
        {70, 72, 75, 76, 90, 90, 91, 93, 93, 98},
        {84, 85, 93, 95, 96, 97, 97, 99, 100, 100}};

    int target = 63;

    cout << search(matrix, 10, 10, target) << endl;

    return 0;
}