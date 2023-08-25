// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() > 1)
    {
        int u = st.top();
        st.pop();
        int v = st.top();
        st.pop();

        if (M[u][v] == 0)
            st.push(u);

        if (M[v][u] == 0)
            st.push(v);
    }

    if (st.size() == 0)
        return -1;

    int rem = st.top();

    for (auto i : M[rem])
        if (i == 1)
            return -1;

    for (int i = 0; i < n; i++)
        if (i != rem && M[i][rem] == 0)
            return -1;

    return rem;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> M{{0, 1, 0},
                          {0, 0, 0},
                          {0, 1, 0}};

    int n = M.size();

    cout << celebrity(M, n);

    return 0;
}