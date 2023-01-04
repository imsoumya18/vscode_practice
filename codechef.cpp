// @author Soumya
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int test(int iuewe)
{
    for (int i = 2; i * i < iuewe; i++)
        if (iuewe % i == 0)
            return i;

    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int hvrbejbv = test(n);

        if (hvrbejbv == -1)
            cout << -1 << endl;
        else
            cout << hvrbejbv << " " << (n / hvrbejbv) << " " << 1 << endl;
    }

    return 0;
}