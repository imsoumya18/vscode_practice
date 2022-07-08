// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int numUniqueEmails(vector<string> &emails)
{
    set<string> s;

    for (auto i : emails)
    {
        string dom = i.substr(i.find('@') + 1);
        string local_name = i.substr(0, i.find('@'));
        string nlocal_name = "";

        for (auto j : local_name)
            if (j == '+')
                break;
            else if (j == '.')
                continue;
            else
                nlocal_name.push_back(j);

        s.insert(nlocal_name + "@" + dom);
    }

    return s.size();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<string> emails{"test.email+alex@leetcode.com", "test.email.leet+alex@code.com"};

    cout << numUniqueEmails(emails) << endl;

    return 0;
}