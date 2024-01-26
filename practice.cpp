// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int lin_search(vector<int> vct, int k)
{
    for (int i = 0; i < vct.size(); i++)
        if (vct[i] == k)
            return i;

    return -1;
}

int bin_search(vector<int> vct, int k, int l, int r)
{
    int mid = l + (r - l) / 2;

    while (l < r)
    {
        if (vct[mid] == k)
            return mid;
        else if (vct[mid] > k)
            r = mid - 1;
        else
            l = mid + 1;

        mid = l + (r - l) / 2;
    }

    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 60;

    cout << bin_search(vct, k, 0, vct.size() - 1) << endl;

    return 0;
}