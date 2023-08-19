// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

bool test(int n)
{
    int evenDigit = 0, oddDigit = 0;

    while (n != 0)
    {
        int rem = n % 10;
        n /= 10;

        if (rem % 2 == 0)
            evenDigit++;
        else
            oddDigit++;
    }

    if (evenDigit == oddDigit)
        return true;

    return false;
}

int numberOfBeautifulIntegers(int low, int high, int k)
{
    vector<int> vct;
    int cnt = 0, first = low;

    if (low % k != 0)
        first = low + (k - low % k);

    while (first <= high)
    {
        if (test(first))
            cnt++;

        first += k;
    }

    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int low = 36, high = 60, k = 3;

    cout << numberOfBeautifulIntegers(low, high, k) << endl;

    return 0;
}