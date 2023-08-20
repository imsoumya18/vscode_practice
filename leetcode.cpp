// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int minimumSum(int n, int k)
{
    set<int> s;
    int i = 1, ans = 0;

    while (s.size() != n)
    {
        if (s.find(k - i) == s.end())
        {
            s.insert(i);
            ans += i;
        }
        i++;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 5, k = 4;

    cout << minimumSum(n, k) << endl;

    return 0;
}