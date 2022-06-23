// @author Soumya
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
    {
        vector<string> vct;
        return vct;
    }

    vector<string> vct{""};

    string keys[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for (auto i : digits)
    {
        vector<string> temp = vct;
        vct.clear();
        for (auto j : temp)
            for (auto k : keys[i - '0'])
                vct.push_back(j + k);
    }

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s = "2";

    for (auto i : letterCombinations(s))
        cout << i << endl;

    return 0;
}