// @author Soumya
#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, i;
    cin >> t;

    for (i = 1; i <= t; i++)
    {
        int n, j;
        cin >> n;
        int arr[n];
        for (j = 0; j < n; j++)
            cin >> arr[j];

        cout << "Case #" << i << ": ";
    }

    return 0;
}