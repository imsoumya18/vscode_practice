// @author Soumya
#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    if (x == 1)
        return 1;

    int cnt = 0;
    double res = 1;

    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }

    while (cnt != n)
    {
        res *= x;
        cnt++;
    }

    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    double x = -2;
    int n = -2;

    cout << myPow(x, n);

    return 0;
}