// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &vct)
{
    for (int i = 0; i < vct.size() - 1; i++)
        for (int j = i + 1; j < vct.size(); j++)
            if (vct[j] < vct[i])
                swap(vct[i], vct[j]);
}

void bubble_sort(vector<int> &vct)
{
    for (int i = 0; i < vct.size() - 1; i++)
        for (int j = 0; j < vct.size() - i - 1; j++)
            if (vct[j + 1] < vct[j])
                swap(vct[j], vct[j + 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{5, 4, 3, 2, 1, 0, -1, -2, -3};

    for (auto i : vct)
        cout << i << " ";

    cout << endl;

    bubble_sort(vct);

    for (auto i : vct)
        cout << i << " ";

    cout << endl;

    return 0;
}