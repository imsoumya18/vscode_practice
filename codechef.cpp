// @author Soumya
#include <iostream>
#include <map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, i = 1, j;
    cin >> n;

    while (i <= n)
    {
        j = 1;
        while (j <= n - i)
        {
            cout << "  ";
            j += 1;
        }

        j = 1;
        while (j <= i)
        {
            cout << j << " ";
            j += 1;
        }

        j = j - 2;
        while (j >= 1)
        {
            cout << j << " ";
            j -= 1;
        }

        cout << endl;
        i += 1;
    }

    return 0;
}