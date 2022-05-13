// @author Soumya
#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        if (n % 4 == 2 || n % 4 == 3)
            cout << 3 << endl;
        else if (n % 4 == 0)
            cout << n + 3 << endl;
        else if (n % 4 == 1)
            cout << n << endl;
    }

    return 0;
}