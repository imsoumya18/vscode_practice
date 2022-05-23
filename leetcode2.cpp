// @author Soumya
#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
        return 1;

    long long nn = n;

    if (nn < 0)
    {
        x = 1 / x;
        nn = nn * (-1);
    }

    if (nn % 2 == 0)
    {
        double temp = myPow(x, nn / 2);
        return temp * temp;
    }
    else
    {
        double temp = myPow(x, nn - 1);
        return x * temp;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    double x = -2;
    int n = 5;

    cout << myPow(x, n);

    return 0;
}