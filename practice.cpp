// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs_graph(int n, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
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

                for (auto j : adj[node])
                    if (!vis[j])
                    {
                        q.push(j);
                        vis[j] = 1;
                    }
            }
        }
    }

    return bfs;
}

void dfs(int node, vector<int> adj[], vector<int> &dfs_store, vector<int> &vis)
{
    dfs_store.push_back(node);
    vis[node] = 1;

    for (auto i : adj[node])
        if (!vis[i])
            dfs(i, adj, dfs_store, vis);
}

vector<int> dfs_graph(int n, vector<int> adj[])
{
    vector<int> dfs_store;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, adj, dfs_store, vis);

    return dfs_store;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << "-->    ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    for (auto i : bfs_graph(n, adj))
        cout << i << " ";

    cout << endl;

    for (auto i : dfs_graph(n, adj))
        cout << i << " ";

    return 0;
}