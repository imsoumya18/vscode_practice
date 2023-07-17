// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int setBits(int a, int b)
{
    int ans = 0;

    while (a != 0 && b != 0)
    {
        ans += (a & 1);
        a = a >> 1;

        ans += (b & 1);
        b = b >> 1;
    }

    while (a != 0)
    {
        ans += (a & 1);
        a = a >> 1;
    }

    while (b != 0)
    {
        ans += (b & 1);
        b = b >> 1;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a = 5, b = 11;

    cout << setBits(a, b) << endl;

    return 0;
}