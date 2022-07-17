// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> vct;
    int i = 0, j = 0, tot = nums1.size() + nums2.size();

    while (i < nums1.size() || j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            vct.push_back(nums1[i]);
            i++;
        }
        else
        {
            vct.push_back(nums2[j]);
            j++;
        }
        if (i == nums1.size())
        {
            vct.push_back(nums2[j]);
            j++;
        }
        if (j == nums2.size())
        {
            vct.push_back(nums1[i]);
            i++;
        }
    }

    for (auto i : vct)
        cout << i << endl;

    if (tot % 2 == 0)
    {
        double ans = (vct[tot / 2] + vct[tot / 2 - 1]) / tot;
        return ans;
    }
    else
    {
        double ans = vct[tot / 2] / tot;
        return double(ans);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums1{1, 3}, nums2{2, 4, 5, 6};

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}