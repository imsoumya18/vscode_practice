// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

void rev_stack(stack<int> &st)
{
    stack<int> temp;
    int tp;

    while (!st.size() !=0)
    {
        tp = st.top();
        st.pop();
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        st.push(tp);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    rev_stack(st);

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}