// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int longest_alternate_subs(vector<int> &arr, int n)
{
    vector<vector<int>> vct(n, vector<int>(2, 1));

    int len = 1;

    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j])
            {
                vct[i][0] = max(vct[i][0], vct[j][1] + 1);
            }
            else if (arr[i] < arr[j])
            {
                vct[i][1] = max(vct[i][1], vct[j][0] + 1);
            }
        }

    for (int i = 0; i < n; ++i)
        len = max(len, max(vct[i][0], vct[i][1]));

    return len;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr{1, 7, 4, 9, 2, 5};

    cout << longest_alternate_subs(arr, arr.size()) << endl;

    return 0;
}