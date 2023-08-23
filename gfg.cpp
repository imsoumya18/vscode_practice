// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

char *reverse(char *S, int len)
{
    char ans[len];
    stack<char> st;

    for (int i = 0; i < len; i++)
        st.push(i);

    int i = 0;

    while (!st.empty())
    {
        ans[i] = st.top();
        st.pop();
        i++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char S[] = "GeeksForGeeks";

    return 0;
}