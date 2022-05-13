// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solve(vector<int> &A)
{
    int arr[100000] = {0}, i, min = A.size();

    for (i = A.size() - 1; i >= 0; i--)
    {
        if (arr[A[i]] == 0)
            arr[A[i]] = 1;
        else if (i < min)
            min = i;
    }

    if (min == A.size())
        return -1;
    else
        return A[min];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> A{10, 5, 3, 4, 3, 5, 6};

    cout << solve(A);

    return 0;
}