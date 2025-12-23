// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
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

void rev(vector<int> &nums, int l, int r)
{
    while (l <= r)
    {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}

int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    unordered_set<int> st;
    int mxlen = 1;

    for (auto it : nums)
        st.insert(it);

    for (auto it : st)
        if (st.find(it - 1) == st.end())
        {
            int currlen = 0, curr = it;

            while (st.find(curr) != st.end())
            {
                curr++;
                currlen++;
            }

            mxlen = max(mxlen, currlen);
        }

    return mxlen;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
