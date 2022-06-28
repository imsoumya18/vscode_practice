// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> vct;
    vector<string> temp = strs;
    set<string> s;

    for (auto p : temp)
    {
        for (int i = 0; i < p.size() - 1; i++)
            for (int j = i + 1; j < p.size(); j++)
                if (p[j] < p[i])
                    swap(p[i], p[j]);
        s.insert(p);
    }

    for (auto i : s)
        cout << i << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    groupAnagrams(strs);

    // for (auto i : groupAnagrams(strs))
    // {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }

    return 0;
}