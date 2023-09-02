// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool checkStrings(string s1, string s2)
{
    for (int i = 0; i < s1.size() - 2; i++)
    {
        int j;

        if (i % 2 == 0)
            j = 0;
        else
            j = 1;

        for (j; j < s1.size(); j += 2)
            if (i != j && s1[i] == s2[j] && s1[j] == s2[i])
            {
                swap(s1[i], s1[j]);
                break;
            }
    }

    return (s1 == s2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1 = "abcdba", s2 = "cabdab";

    cout << checkStrings(s1, s2) << endl;

    return 0;
}