// @author Soumya
#include <iostream>
using namespace std;

int search(int A[], int l, int h, int key)
{
    int n = h + 1;
    int mid = (l + h) / 2;

    while (l < h)
    {
        if (A[mid] >= A[0])
            l = mid + 1;
        else
            h = mid;

        mid = (l + h) / 2;
    }

    if (key >= A[0])
    {
        l = 0;
        h--;
    }
    else
    {
        l = h;
        h = n - 1;
    }

    mid = (l + h) / 2;

    while (l <= h)
    {
        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            l = mid + 1;
        else
            h = mid - 1;

        mid = (l + h) / 2;
    }

    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};

    return 0;
}