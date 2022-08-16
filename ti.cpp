// @author Soumya
#include <iostream>
#include <time>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 15, i = 1, cnt = 0;

    while (n)
    {
        if (n & i == 1)
            cnt++;
        n >> i;
    }

    cout << cnt << endl;
    n = ((1 << 14) | n);
    n = ((1 << 15) | n);
    n = (~(1 << 14) & n);

    int r[2], g[2], y[2];

    r[0] = 0;

    time.sleep(30);

    r[0] ^ g[0] = 1;
    r[0] ^ y[0] = 1;
    r[1] ^ g[1] = 1;
    r[1] ^ y[1] = 1;
    r[0] ^ r[1] = 1;
    y[0] ^ y[1] = 1;
    g[0] ^ g[1] = 1;

    return 0;
}