// @author Soumya
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int maxConsecutiveOnes(int n)
{
    int curr = 0, mx = 0;

    while (n != 0)
    {
        if (n % 2 == 1)
            curr += 1;
        else
        {
            mx = max(curr, mx);
            curr = 0;
        }

        n = n / 2;
    }

    mx = max(curr, mx);

    return mx;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N = 222;

    cout << maxConsecutiveOnes(N) << endl;

    return 0;
}