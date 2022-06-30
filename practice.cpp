// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &vct)
{
    for (int i = 1; i < vct.size(); i++)
        for (int j = 0; j < i; j++)
            if (vct[j] > vct[i])
            {
                int temp = vct[i];
                for (int k = i; k > j; k--)
                    vct[k] = vct[k - 1];
                vct[j] = temp;
            }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{12, 45, 23, 51, 19, 8};

    for (auto i : vct)
        cout << i << " ";
    cout << endl;

    insertion_sort(vct);

    for (auto i : vct)
        cout << i << " ";

    return 0;
}