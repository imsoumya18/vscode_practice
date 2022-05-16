// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

void insert_bottom(stack<int> &st, int top_ele)
{
    if (st.empty())
    {
        st.push(top_ele);
        return;
    }

    int ele = st.top();
    st.pop();
    insert_bottom(st, top_ele);
    st.push(ele);
}

void rev_stack(stack<int> &st)
{
    if (st.empty())
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