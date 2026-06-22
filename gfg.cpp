// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    unordered_map<char, vector<int>> mp;

    mp['a'].push_back(3);
    mp['a'].push_back(4);

    print(mp['a']);
    print(mp['b']);

    cout << mp.size() << endl;

    mp.erase('a');
    cout << mp.size() << endl;

    return 0;
}