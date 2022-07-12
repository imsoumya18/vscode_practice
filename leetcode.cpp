// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string decodeString(string s)
{
    stack<char> st;
    string ans;

    for (auto i : s)
    {
        ans = "";
        if (i == ']')
        {
            while (!st.empty() && st.top() != '[')
            {
                ans = st.top() + ans;
                st.pop();
            }
            st.pop();
            int n = 0, mult = 1;
            while (!st.empty() && isdigit(st.top()))
            {
                n += mult * (st.top() - '0');
                mult *= 10;
                st.pop();
            }
            for (int j = 1; j <= n; j++)
                for (auto k : ans)
                    st.push(k);
        }
        else
            st.push(i);
    }

    ans = "";

    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s = "100[leetcode]";

    cout << decodeString(s) << endl;

    return 0;
}