// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &vct, int l, int r)
{
    while (l < r)
    {
        swap(vct[l], vct[r]);
        l++;
        r--;
    }
}

bool check(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return true;

    int it = 0;

    while (it < n - 1)
    {
        if (nums[it] > nums[it + 1])
            break;
        it++;
    }

    if (it == n - 1)
        return true;

    it++;

    while (it < n - 1)
    {
        if (nums[it] > nums[it + 1])
            return false;
        it++;
    }

    if (nums[n - 1] > nums[0])
        return false;

    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{1, 3, 2};

    for (auto i : nums)
        cout << i << " ";

    cout << endl;

    cout << check(nums) << endl;

    return 0;
}