// @author Soumya
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
        int n, m;
        vector<int> a, b, d;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            b.push_back(x);
        }

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            d.push_back(x);
        }

        bool flag = false;

        for (auto i : b)
            if (d[m - 1] == i)
            {
                flag = true;
                break;
            }

        if (flag == false)
            cout << "NO" << endl;
        else
        {
            unordered_map<int, int> freq;

            for (auto i : d)
                freq[i]++;

            bool flag = true;

            for (int i = 0; i < n; i++)
                if (a[i] != b[i])
                {
                    if (freq.find(b[i]) == freq.end())
                    {
                        cout << "NO" << endl;
                        flag = false;
                        break;
                    }
                    else
                    {
                        freq[b[i]]--;
                        if (freq[b[i]] == 0)
                            freq.erase(b[i]);
                    }
                }

            if (flag == true)
                cout << "YES" << endl;
        }
    }

    return 0;
}