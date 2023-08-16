// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &vct)
{
    int n = vct.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (vct[j] < vct[i])
                swap(vct[i], vct[j]);
}

void bubble_sort(vector<int> &vct)
{
    int n = vct.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (vct[j + 1] < vct[j])
                swap(vct[j], vct[j + 1]);
}

void insertion_sort(vector<int> &vct)
{
    int n = vct.size();

    for (int i = 1; i < n; i++)
    {
        int temp = vct[i];
        int j = i - 1;

        while (vct[j] > temp && j >= 0)
        {
            vct[j + 1] = vct[j];
            j--;
        }

        vct[j + 1] = temp;
    }
}

void merge(vector<int> &vct, int l, int mid, int r)
{
    vector<int> vct1, vct2;

    for (int i = l; i <= mid; i++)
        vct1.push_back(vct[i]);

    for (int i = mid + 1; i <= r; i++)
        vct2.push_back(vct[i]);

    int i = l, j = 0, k = 0;

    while (j < vct1.size() && k < vct2.size())
    {
        if (vct1[j] < vct2[k])
        {
            vct[i] = vct1[j];
            i++;
            j++;
        }
        else
        {
            vct[i] = vct2[k];
            i++;
            k++;
        }
    }

    while (j < vct1.size())
    {
        vct[i] = vct1[j];
        i++;
        j++;
    }

    while (k < vct2.size())
    {
        vct[i] = vct2[k];
        i++;
        k++;
    }
}

void merge_sort(vector<int> &vct, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        merge_sort(vct, l, mid);
        merge_sort(vct, mid + 1, r);

        merge(vct, l, mid, r);
    }
}

int partition(vector<int> &vct, int l, int r)
{
    int pivot = vct[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
        if (vct[j] < pivot)
        {
            i++;
            swap(vct[i], vct[j]);
        }

    i++;
    swap(vct[i], vct[r]);
    return i;
}

void quick_sort(vector<int> &vct, int l, int r)
{
    if (l < r)
    {
        int pi = partition(vct, l, r);

        quick_sort(vct, l, pi - 1);
        quick_sort(vct, pi + 1, r);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> vct{9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (auto i : vct)
        cout << i << " ";
    cout << endl;

    quick_sort(vct, 0, vct.size() - 1);

    for (auto i : vct)
        cout << i << " ";
    cout << endl;

    return 0;
}