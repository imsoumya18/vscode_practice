// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int minJumps(int arr[], int n)
{
    int cnt = 0, i = 0;

    while (i < n - 1)
    {
        if (i + arr[i] > n - 1)
            i = n - 1;
        else if (arr[i] == 0)
            return -1;
        else
            i += arr[i];

        cnt++;
    }

    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1}, n = 10;

    cout << minJumps(arr, n) << endl;

    return 0;
}