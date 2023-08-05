// @author Soumya
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int minimumSeconds(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> mp;
    int maxfreqele = 0;

    for (auto i : nums)
    {
        if (mp.find(i) == mp.end())
            mp[i] = 1;
        else
            mp[i]++;

        if (mp[i] > mp[maxfreqele])
            maxfreqele = i;
    }

    int cnt = 0;

    while (1)
    {
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxfreqele)
            {
                nums[(i - 1 + n) % n] = nums[i];
                nums[(i + 1) % n] = nums[i];
            }
            else
                flag = 1;
        }

        for (auto x : nums)
            cout << x << " ";
        cout << endl;

        cnt++;

        if (flag == 0)
        {
            cnt--;
            break;
        }
    }

    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums{2, 1, 3, 3, 2};

    cout << minimumSeconds(nums) << endl;

    return 0;
}