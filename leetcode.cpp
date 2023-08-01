// @author Soumya
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void segregateElements(int arr[], int n)
{
    int lo = 0, hi = n - 1;

    while (lo < hi)
        if (arr[lo] < 0 && arr[hi] >= 0)
        {
            swap(arr[lo], arr[hi]);
            lo++;
            hi--;
        }
        else if (arr[lo] >= 0 && arr[hi] < 0)
        {
            lo++;
            hi--;
        }
        else if (arr[lo] >= 0 && arr[hi] >= 0)
            lo++;
        else
            hi--;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6}, n = 8;

    segregateElements(arr, n);

    for (auto i : arr)
        cout << i << " ";

    return 0;
}