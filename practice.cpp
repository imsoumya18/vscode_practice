// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int func(int num)
{
    int i = 0, j = num, poss = 0;
    while (i <= j)
    {
        if (to_string(i) == to_string(j)[-1])
        {
            poss = 1;
            break;
        }
        i += 1;
        j -= 1;
    }
    if (poss)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> parcels{6, 5, 4, 1, 3};
    int k = 7;

    cout << getMinimumCost(parcels, k) << endl;

    return 0;
}