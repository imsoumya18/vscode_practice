// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i = 1, j, res, flag, cnt = 0, A = 4, B = 7;
    for (i = 1; i <= A; i++)
    {
        res = 1;
        j = i;
        while (j > 0)
        {
            res *= j;
            j--;
        }
        res += B;
        flag = 0;
        for (j = 2; j <= res / 2; j++)
        {
            if (res % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}