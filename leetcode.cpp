// @author Soumya
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int minPartitions(string n)
{
    int maxi = 0;
    for (auto i : n)
    {
        if (i - '0' > maxi)
            maxi = i - '0';
    }

    return maxi;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s = "27346209830709182346";

    cout << minPartitions(s) << endl;

    return 0;
}