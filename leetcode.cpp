// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void segregateElements(int arr[], int n)
{
    vector<int> temp;
    int start = 0;

    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            temp.push_back(arr[i]);
        else
        {
            arr[start] = arr[i];
            start++;
        }

    for (auto i : temp)
    {
        arr[start] = i;
        start++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6}, n = 8;

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    segregateElements(arr, n);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}