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

bool check(vector<int> &nums)
{
    int n = nums.size(), cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            cnt++;

        if (cnt > 1)
            return false;
    }

    if (cnt == 1 && nums[0] > nums[n - 1])
        return true;

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{5, 4, 3, 2, 1};

    print1d(vct);

    quick_sort(vct, 0, vct.size() - 1);

    print1d(vct);

    return 0;
}
