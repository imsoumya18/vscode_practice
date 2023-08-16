// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans{{}}, temp;
    temp = ans;

    for (auto i : nums)
    {
        for (auto j : temp)
        {
            j.push_back(i);
            ans.push_back(j);
        }
        temp = ans;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{2, 4};

    vector<vector<int>> ans = subsets(nums);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}