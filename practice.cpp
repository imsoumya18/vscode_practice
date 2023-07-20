// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int lo = 0, hi = arr.size() - 1;
    int mid = (lo + hi) / 2;

    while (lo < hi)
    {
        if (arr[mid] < arr[mid + 1])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }

        mid = (lo + hi) / 2;
    }

    return mid;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{0, 10, 5, 2};

    cout << peakIndexInMountainArray(vct) << endl;

    return 0;
}