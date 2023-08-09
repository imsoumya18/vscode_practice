// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int lo = -1, hi = n - 1;

    for (int i = n - 2; i >= 0; i--)
        if (nums[i] < nums[i + 1])
        {
            lo = i;
            break;
        }

    if (lo != -1)
    {
        while (nums[hi] < nums[lo])
            hi--;

        swap(nums[lo], nums[hi]);
    }

    lo++;
    hi = n - 1;

    while (lo < hi)
    {
        swap(nums[lo], nums[hi]);
        lo++;
        hi--;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{3, 2, 1};

    for (auto i : nums)
        cout << i << " ";
    cout << endl;

    nextPermutation(nums);

    for (auto i : nums)
        cout << i << " ";
    cout << endl;

    return 0;
}