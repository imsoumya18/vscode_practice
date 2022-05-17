// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<string> reorderLogFiles(vector<string> &logs)
{
    int start = 0;
    for (int i = 0; i < logs.size(); i++)
    {
        int j = 0;
        while (logs[i][j] != ' ')
            j++;
        if (!isdigit(logs[i][j + 1]))
        {
            swap(logs[i], logs[start]);
            start++;
        }
    }
    return logs;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<string> logs;

    logs.push_back("dig1 8 1 5 1");
    logs.push_back("let1 art can");
    logs.push_back("dig2 3 6");
    logs.push_back("let2 own kit dig");
    logs.push_back("let3 art zero");

    for (auto i : reorderLogFiles(logs))
        cout << i << endl;

    return 0;
}