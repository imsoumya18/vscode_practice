// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> visited)
{
    if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1)
        return true;

    return false;
}

void solve(vector<vector<int>> &m, int n, vector<vector<int>> visited, vector<string> &ans, int x, int y, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    if (isSafe(x - 1, y, m, n, visited))
    {
        path.append("U");
        solve(m, n, visited, ans, x - 1, y, path);
        path.pop_back();
    }

    if (isSafe(x + 1, y, m, n, visited))
    {
        path.append("D");
        solve(m, n, visited, ans, x + 1, y, path);
        path.pop_back();
    }

    if (isSafe(x, y - 1, m, n, visited))
    {
        path.append("L");
        solve(m, n, visited, ans, x, y - 1, path);
        path.pop_back();
    }

    if (isSafe(x, y + 1, m, n, visited))
    {
        path.append("R");
        solve(m, n, visited, ans, x, y + 1, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;

    if (m[0][0] == 0)
        return ans;

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";

    int x = 0, y = 0;
    solve(m, n, visited, ans, x, y, path);
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> m{{1, 0, 0, 0},
                          {1, 1, 0, 1},
                          {1, 1, 0, 0},
                          {0, 1, 1, 1}};

    int n = 4;

    vector<string> vct = findPath(m, n);

    for (auto i : vct)
        cout << i << endl;

    return 0;
}