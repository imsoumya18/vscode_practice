// @author Soumya
#include <iostream>
#include <map>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    int cnt = 0;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (int i = 0; i < n; i++)
    {
        cnt += mp[k - arr[i]];

        if (k - arr[i] == arr[i])
            cnt--;
    }

    return cnt/2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[] = {1, 5, 5, 5, 5, 7};
    int n = 6, k = 10;

    cout << getPairsCount(arr, n, k) << endl;

    return 0;
}