// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canBeIncreasing(vector<int> &nums)
{
    int flag = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] <= nums[i])
            if (nums[i + 1] >= nums[i - 1])
                flag++;
    }

    if (flag == 0 || flag == 1)
        return true;

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{2, 3, 1, 2};

    cout << canBeIncreasing(nums) << endl;

    return 0;
}