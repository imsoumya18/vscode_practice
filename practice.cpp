// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vct, int lo, int mid, int hi)
{
    vector<int> vct1, vct2;

    for (int i = lo; i <= mid; i++)
        vct1.push_back(vct[i]);

    for (int i = mid + 1; i <= hi; i++)
        vct2.push_back(vct[i]);

    int i = lo, j = 0, k = 0;

    while (j < vct1.size() && k < vct2.size())
    {
        if (vct1[j] <= vct2[k])
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

void merge_sort(vector<int> &vct, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = (lo + hi) / 2;

        merge_sort(vct, lo, mid);
        merge_sort(vct, mid + 1, hi);

        merge(vct, lo, mid, hi);
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

    merge_sort(vct, 0, vct.size() - 1);

    for (auto i : vct)
        cout << i << " ";
    cout << endl;

    return 0;
}