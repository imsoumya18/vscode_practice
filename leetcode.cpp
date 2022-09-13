// @author Soumya
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> vct;
    Solution(vector<int> &nums)
    {
        vct = nums;
    }

    int pick(int target)
    {
        vector<int> temp;

        for (int i = 0; i < vct.size(); i++)
            if (vct[i] == target)
                cout << "test" << " ";
        // temp.push_back(i);

        return rand() % temp.size();
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution *obj = new Solution(nums);
    obj->pick(1);

    return 0;
}