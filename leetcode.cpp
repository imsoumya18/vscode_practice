// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int maxSubStr(string str)
{
    int ans = 0;
    int curr1 = 0, curr2 = 0;

    for (int i = 0; i < str.size(); i++)
        if (i > 0 && str[i] == str[0] && str[i - 1] != str[0])
        {
            ans++;

            if (curr2 > curr1)
                curr2 -= curr1;
        }

    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str = "0100110101";

    cout << maxSubStr(str) << endl;

    return 0;
}