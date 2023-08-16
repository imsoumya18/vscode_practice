// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void solve(string digits, string output, vector<string> &ans, int idx, vector<string> keypad)
{
    if (idx >= digits.size())
    {
        if (output != "")
            ans.push_back(output);
        return;
    }

    int number = digits[idx] - '0';
    string value = keypad[number];

    for (auto i : value)
    {
        output.push_back(i);
        solve(digits, output, ans, idx + 1, keypad);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string output;

    int idx = 0;

    vector<string> keypad = {"",
                             "",
                             "abc",
                             "def",
                             "ghi",
                             "jkl",
                             "mno",
                             "pqrs",
                             "tuv",
                             "wxyz"};

    solve(digits, output, ans, idx, keypad);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string digits = "";

    vector<string> ans = letterCombinations(digits);

    for (auto i : ans)
        cout << i << endl;

    return 0;
}