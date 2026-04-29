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

string preToInfix(string pre_exp)
{
    // Write your code here
    stack<string> st;

    for (int i = pre_exp.size() - 1; i >= 0; i--)
    {
        char c = pre_exp[i];

        if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
        {
            string l = st.top();
            st.pop();
            string r = st.top();
            st.pop();

            st.push("(" + l + c + r + ")");
        }
        else
            st.push(string(1, c));
    }

    return st.top();
}

string infixToPostfix(string &s)
{
    // code here
    unordered_map<char, int> priority;
    stack<char> st;
    string ans;

    priority['^'] = 3;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['+'] = 1;
    priority['-'] = 1;

    for (auto c : s)
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            ans += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            st.pop();
        }
        else
        {
            while (!st.empty() && (priority[st.top()] > priority[c] || (priority[st.top()] == priority[c] && c != '^')))
            {
                ans += st.top();
                st.pop();
            }

            st.push(c);
        }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string preToPost(string pre_exp)
{
    string ans = preToInfix(pre_exp);
    ans = infixToPostfix(ans);

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}