// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<int> executeInstructions(int n, vector<int> &startPos, string s)
{
    vector<int> vct;

    for (int i = 0; i < s.size(); i++)
    {
        int cnt = 0;

        for (int j = i; j < s.size(); j++)
        {
            if (s[j] == 'R')
                startPos[1]++;
            else if (s[j] == 'L')
                startPos[1]--;
            else if (s[j] == 'U')
                startPos[0]--;
            else
                startPos[0]++;

            if (startPos[0] < 0 || startPos[0] >= n || startPos[1] < 0 || startPos[1] >= n)
                break;

            cnt++;
        }

        vct.push_back(cnt);
    }

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s = "RRDDLU";
    int n = 3;
    vector<int> startPos{0, 1};

    for (auto i : executeInstructions(n, startPos, s))
        cout << i << " ";

    return 0;
}