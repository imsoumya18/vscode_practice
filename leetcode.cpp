// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<string> braceExpansionII(string expression)
{
    vector<string> vct;
    int j = 0;

    for (int i = 0; i < expression.size(); i++)
        if (expression[i] != ',' && (expression[i + 1] == '{') || i + 1 == expression.size())
        {
            string temp = "";
            for (++j; j < i; j++)
                temp += expression[j];
            vct.push_back(temp);
            j++;
        }
    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string expression = "{a,b}{c,{d,e}}";

    for (auto i : braceExpansionII(expression))
        cout << i << endl;

    return 0;
}