// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

void rev_string(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word)test;
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    getline(cin, s);

    rev_string(s);

    return 0;
}