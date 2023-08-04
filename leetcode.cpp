// @author Soumya
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    set<int> s, ans;

    for (auto i : nums1)
        s.insert(i);

    for (auto j : nums2)
        if (s.find(j) != s.end())
            ans.insert(j);

    vector<int> vct(ans.begin(), ans.end());

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums1{1, 2, 2, 1}, nums2{2, 2};

    vector<int> vct = intersection(nums1, nums2);

    for (auto i : vct)
        cout << i << endl;

    return 0;
}