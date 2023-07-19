// @author Soumya
#include <iostream>
#include <map>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    int cnt = 0;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(k - arr[i]) == mp.end())
            mp[arr[i]] = 1;
        else
        {
            cnt += mp[k - arr[i]];
            mp[arr[i]]++;
        }
    }

    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[] = {1, 5, 5, 5, 5, 5, 7};
    int n = 6, k = 10;

    cout << getPairsCount(arr, n, k) << endl;

    return 0;
}