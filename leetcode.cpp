// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if (b > a)
        swap(a, b);

    if (b == 0)
        return a;

    return gcd(a % b, b);
}

int findGCD(vector<int> &nums)
{
    int maxi = nums[0], mini = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
        mini = min(mini, nums[i]);
    }

    return gcd(maxi, mini);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{2, 5, 6, 9, 10};

    cout << findGCD(nums) << endl;

    return 0;
}