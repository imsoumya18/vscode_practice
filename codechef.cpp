// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string str;
        cin >> str;

        stack<int> st;
        st.push(str[0]);

        for (int i = 1; i < n; i++)
        {
            if (st.top() == str[i])
            {
                st.pop();
                st.push(0);
            }
            else
                st.push(str[i]);
        }

        if (st.size() == 1)
            cout << "YES" << endl;
        else
        {
            char c = st.top();
            st.pop();

            while (!st.empty() && st.top() == c)
                st.pop();

            if (st.empty())
                cout << 'YES' << endl;
            else
                cout << 'NO' << endl;
        }
    }

    return 0;
}