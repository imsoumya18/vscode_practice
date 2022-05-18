// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> subs;
    vector<vector<int>> subs2;
    vector<int> temp;
    subs.push_back(temp);

    for (auto i : nums)
    {
        for (auto j : subs)
        {
            subs2.push_back(j);
            j.push_back(i);
            subs2.push_back(j);
        }
        subs = subs2;
        subs2.clear();
    }

    return subs;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{1, 2, 3};

    for (auto i : subsets(nums))
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}