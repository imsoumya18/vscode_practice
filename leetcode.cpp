// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void print1d(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";

    cout << endl;
}

void print2d(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int maxSubArray(vector<int> &nums)
{
    int sum = 0, maxsum = 0;

    for (auto it : nums)
    {
        sum += it;
        maxsum = max(maxsum, sum);

        if (sum < 0)
            sum = 0;
    }

    return maxsum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
