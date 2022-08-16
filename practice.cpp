// @author Soumya
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string st = "abcdef", temp = "";

    for (int i = 0; i < st.size(); i++)
    {
        temp += st[i];
        cout << i << " " << temp << " " << st.substr(i + 1) << endl;
    }

    return 0;
}