// @author Soumya
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxIncreasingGroups(vector<int> &usageLimits)
{
    int ans = 1;
    sort(usageLimits.begin(), usageLimits.end());

    for (int i = 0; i < usageLimits.size() - 1; i++)
        if (usageLimits[i] < usageLimits[i + 1])
            ans++;
        else
            break;

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> usageLimits{1,1};

    cout << maxIncreasingGroups(usageLimits) << endl;
    return 0;
}