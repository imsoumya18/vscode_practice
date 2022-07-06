// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
{
    vector<int> vct;
    set<int> id;
    pair<int, set<int>> pr;

    for (auto i : logs)
    {
        id.insert(i[0]);
    }

    for (auto i : id)
        cout << i << " ";

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> logs{{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
    int k = 5;

    findingUsersActiveMinutes(logs, k);

    return 0;
}