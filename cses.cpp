// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

#define ll long long

int nCr(int n, int r)
{
    int res = 1;

    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main()
{
    int n = 4, r = 2;

    cout << nCr(n, r) << endl;

    return 0;
}
