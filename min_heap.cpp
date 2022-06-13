// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// min heap insertion
void insert(vector<int> &harr, int p)
{
    harr.push_back(p);

    int n = harr.size() - 1, flag = 0;

    while (flag != 1)
    {
        if (harr[(n - 1) / 2] > harr[n])
            swap(harr[(n - 1) / 2], harr[n]);

        n = (n - 1) / 2;

        if (n == 0)
            flag++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> harr{0, 8, 1, 17, 18, 12, 5};

    insert(harr, 15);

    for (auto i : harr)
        cout << i << " ";

    return 0;
}