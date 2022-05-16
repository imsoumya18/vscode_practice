// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

void insert_bottom(stack<int> &st, int top_ele)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(top_ele);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}

void rev_stack(stack<int> &st)
{
    if (st.size() == 1)
        return;

    int top_ele = st.top();
    st.pop();
    rev_stack(st);
    insert_bottom(st, top_ele);
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