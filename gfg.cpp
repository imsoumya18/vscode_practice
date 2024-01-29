// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr1[j] < arr1[i])
                swap(arr1[i], arr1[j]);

    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (arr2[j] < arr2[i])
                swap(arr2[i], arr2[j]);

    vector<int> vct;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            vct.push_back(arr1[i]);

            int curr = arr1[i];
            while (curr == arr1[i] && i < n)
                i++;
        }
        else if (arr1[i] > arr2[j])
        {
            vct.push_back(arr2[j]);

            int curr = arr2[j];
            while (curr == arr2[j] && j < m)
                j++;
        }
        else
        {
            vct.push_back(arr1[i]);

            int curr = arr1[i];
            while (curr == arr1[i] && i < n)
                i++;

            curr = arr2[j];
            while (curr == arr2[j] && j < m)
                j++;
        }
    }

    while (i < n)
    {
        vct.push_back(arr1[i]);

        int curr = arr1[i];
        while (curr == arr1[i] && i < n)
            i++;
    }

    while (j < m)
    {
        vct.push_back(arr2[j]);

        int curr = arr2[j];
        while (curr == arr2[j] && j < m)
            j++;
    }

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr1[] = {5, 4, 6, 6, 3, 2, 1, 3, 5, 2}, arr2[] = {3, 2, 1, 2, 2};
    int n = 8, m = 5;

    vector<int> res = findUnion(arr1, arr2, n, m);

    for (auto i : res)
        cout << i << " ";

    return 0;
}