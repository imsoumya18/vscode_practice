// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool if_palindrome(string s)
{
    int flag = 0;
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - i - 1])
        {
            flag++;
            break;
        }

    if (flag == 0)
        return true;

    return false;
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> vct;
    for (int i = 0; i < s.size(); i++)
    {
        vector<string> curr;
        string sub1 = s.substr(0, i), sub2 = s.substr(i, s.size());

        if (if_palindrome(sub1))
            curr.push_back(sub1);
        else
            continue;

        cout << sub1 << " " << sub2 << endl;
    }

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s = "aab";

    partition(s);

    return 0;
}