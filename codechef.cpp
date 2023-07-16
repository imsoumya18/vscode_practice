// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int hammingWeight(uint32_t n)
{
    int ans = 0;

    while (n != 0)
    {
        cout << n << "    " << (n & 1) << endl;
        ans += n & 1;
        n = n >> 1;
    }
    cout << endl;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    uint32_t n = 111;

    cout << hammingWeight(n) << endl;

    return 0;
}