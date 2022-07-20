// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int trap(vector<int> &height)
{
    int left[height.size()], right[height.size()];
    int tot = 0, max = -1;

    for (int i = 0; i < height.size(); i++)
    {
        if (height[i] > max)
            max = height[i];
        left[i] = max;
    }
    max = -1;

    for (int i = height.size() - 1; i >= 0; i--)
    {
        if (height[i] > max)
            max = height[i];
        right[i] = max;
    }

    for (int i = 0; i < height.size(); i++)
        if (left[i] < right[i])
            tot += (left[i] - height[i]);
        else
            tot += (right[i] - height[i]);

    return tot;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trap(height) << endl;

    return 0;
}