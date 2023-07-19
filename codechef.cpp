// @author Soumya
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> vct;

    int lo = 0, hi = numbers.size() - 1;
    while (lo < hi)
        if (numbers[lo] + numbers[hi] == target)
        {
            vct.push_back(lo + 1);
            vct.push_back(hi + 1);
            break;
        }
        else if (numbers[lo] + numbers[hi] < target)
            lo++;
        else
            hi--;

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    for (auto i : twoSum(nums, target))
        cout << i << " ";

    return 0;
}