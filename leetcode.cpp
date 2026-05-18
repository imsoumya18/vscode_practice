// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

void print(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int characterReplacement(string s, int k)
{
    int n = s.size(), l = 0, maxlen = 0, maxfreq = 0;
    int freq[26];

    for (int r = 0; r < n; r++)
    {
        freq[s[r] - 'A']++;
        maxfreq = max(maxfreq, freq[s[r] - 'A']);

        while (r - l + 1 - maxfreq > k)
        {
            freq[s[l] - 'A']--;
            l++;
        }

        maxlen = max(maxlen, r - l + 1);
    }

    return maxlen;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}