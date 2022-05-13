// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs_graph(int v, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
            }
        }
    return bfs;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, i;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (i = 1; i <= n; i++)
    {
        cout << i << "-->   ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    for (auto p : bfs_graph(n, adj))
        cout << p << " ";

    return 0;
}