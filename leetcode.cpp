// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int max = 0, min = 0;

    for (int i = 0; i < weights.size(); i++)
    {
        if (weights[i] > min)
            min = weights[i];
        max += weights[i];
    }

    if (max / days < min)
        return min;
    else if (max % days == 0)
        return max / days;

    return max / days + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << shipWithinDays(weights, days) << endl;

    return 0;
}