// @author Soumya
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> idx(K, 0), vct, mx, curr_idx;

    for (auto i : idx)
        cout << i << endl;

    while (vct.size() != K * K)
    mx = arr[0]
        for (int i = 0; i < K; i++)
        

            return idx;
}

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