// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int trap(vector<int> &height)
{
    int tot = 0, curr = 0, i = 0, begin;

    while (height[i] == 0)
        i++;

    begin = i;

    for (++i; i < height.size(); i++)
    {
        if (height[i] < begin)
            curr += (begin - height[i]);
        else
        {
            tot += curr;
            curr = 0;
            begin = height[i];
        }
    }

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