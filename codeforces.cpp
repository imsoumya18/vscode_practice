// @author Soumya
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr1[n], arr2[n];

        for (long long i = 0; i < n; i++)
        {
            cin >> arr1[i];
            arr2[i] = arr1[i];
        }

        sort(arr2, arr2 + n);

        bool tf = false;

        for (long long i = 0; i < n; i++)
        {
            if (arr1[i] != arr2[i])
            {
                cout << 0 << endl;
                tf = 1;
                break;
            }
        }

        if (tf == false)
        {
            long long minn = INT64_MAX;
            long long ind;

            for (long long i = 0; i < n - 1; i++)
                if (arr1[i + 1] - arr1[i] < minn)
                {
                    minn = arr1[i + 1] - arr1[i];
                    ind = i;
                }

            long long ans;
            ans = (arr1[ind + 1] - arr1[ind]) / 2 + 1;
            cout << ans << endl;
        }
    }

    return 0;
}