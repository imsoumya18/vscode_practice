// @author Soumya
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<>
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums1{1, 2, 3, 0, 0, 0}, nums2{2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for (auto i : nums1)
        cout << i << " ";

    return 0;
}