// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

void deleteMid(stack<int> &s, int sizeOfStack)
{
    stack<int> s2;

    while ((s2.size()) < sizeOfStack / 2)
    {
        s2.push(s.top());
        s.pop();
    }

    s.pop();

    while (!s2.empty())
    {
        s.push(s2.top());
        s2.pop();
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // s.push(50);

    deleteMid(s, s.size());

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}