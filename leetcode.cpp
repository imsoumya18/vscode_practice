// @author Soumya
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombinations(string digits)
{
    vector<string> vct;

    string keys[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for (auto i : digits)
    {
        string st = "";
        for (auto j : keys[i - '0'])
            st.push_back(j);
        cout << st << endl;
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

    letterCombinations(s);

    return 0;
}