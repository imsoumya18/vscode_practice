// @author Soumya
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector<string> generateParenthesis(int n)
{
    stack<int> st1, st2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    for (auto i : generateParenthesis(n))
        cout << i << endl;

    return 0;
}