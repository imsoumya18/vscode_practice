// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int max = 0, min = 0, cap, d, curr, ans;

    for (int i = 0; i < weights.size(); i++)
    {
        if (weights[i] > min)
            min = weights[i];
        max += weights[i];
    }
    ans = max;

    while (min < max)
    {
        cap = min + (max - min) / 2;
        d = 0;
        curr = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (curr + weights[i] > cap)
            {
                i--;
                d++;
                curr = 0;
            }
            else
            {
                curr += weights[i];
            }
        }
        d++;

        if (d < days)
        {
            max = cap;
        }
        else if (d > days)
        {
            min = cap;
        }
        else
        {
            if (cap < ans)
            {
                ans = cap;
                max--;
            }
            else
                return ans;
        }
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> weights{1, 2, 3, 1, 1};
    int days = 4;

    cout << shipWithinDays(weights, days) << endl;

    return 0;
}