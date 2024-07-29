// @author Soumya
#include <iostream>
#include <vector>
#include <set>
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

int maxFrequency(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int l = 0, r = 0, n = nums.size();

    int total = 0, maxlen = 0;

    while (r < n)
    {
        total += nums[r];

        while ((r - l + 1) * nums[r] > total + k)
        {
            total -= nums[l];
            l += 1;
        }

        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{3, 9, 6};
    int k = 2;

    cout << maxFrequency(nums, k) << endl;

    return 0;
}
