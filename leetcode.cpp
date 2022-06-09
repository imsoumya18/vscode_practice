// @author Soumya
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> vct;
    for (auto p : strs)
    {
        for (int i = 0; i < p.size() - 1; i++)
            for (int j = 0; j < p.size() - i - 1; j++)
                if (p[j + 1] < p[j])
                    swap(p[j + 1], p[j]);
    }

    for (auto i : strs)
        cout << i << endl;

    return vct;
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