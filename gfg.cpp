// @author Soumya
#include <iostream>
using namespace std;

void segregate0and1(int arr[], int n)
{
    int lo = 0, it = 0;

    while (it < n)
    {
        if (arr[it] == 0)
        {
            swap(arr[lo], arr[it]);
            lo++;
        }
        it++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[] = {0, 0, 1, 1, 0};
    int n = 5;

    segregate0and1(arr, n);

    for (auto i : arr)
        cout << i << " ";

    return 0;
}