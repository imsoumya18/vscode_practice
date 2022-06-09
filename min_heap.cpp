// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &harr, int p)
{
    harr.push_back(p);

    int n = harr.size() - 1, flag = 1;

    while (flag != 0)
    {
        if (harr[(n - 1) / 2] > harr[n])
            swap(harr[(n - 1) / 2], harr[n]);

        n = (n - 1) / 2;
        if (n == 0)
            flag = 0;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> harr{1, 8, 5, 17, 18, 12};

    insert(harr, 4);

    for (auto i : harr)
        cout << i << " ";

    return 0;
}