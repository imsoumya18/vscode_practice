// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

int checkRedundancy(string s)
{
    stack<char> st;
    int cntbraces = 0;
    int cntvars = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ')' && s[i] != '}' && s[i] != ']')
            st.push(s[i]);
        else
        {
            while (st.top() != '(' && st.top() != '{' && st.top() != '[')
            {
                // cout << "test" << endl;
                st.pop();

                cntbraces = 0;
                cntvars++;

                // cntbraces--;
            }

            if ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))
            {
                if (cntvars == 1)
                    return 1;

                st.pop();
                cntbraces++;
                cntvars = 0;

                if (cntbraces > 1)
                    return 1;
            }
        }
    }

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "(a+b+(c))";

    cout << checkRedundancy(s) << endl;

    return 0;
}