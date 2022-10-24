// @author Soumya
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> arr{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    mergeKArrays(arr, 3);

    return 0;
}