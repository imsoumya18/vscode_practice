// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

void print(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void dfs(int node, vector<int> &vis, vector<vector<pair<int, int>>> &adj, stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
        if (!vis[it.first])
            dfs(it.first, vis, adj, st);

    st.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    // code here
    vector<vector<pair<int, int>>> adj(V);
    vector<int> vis(V, 0);

    for (auto e : edges)
        adj[e[0]].push_back({e[1], e[2]});

    stack<int> st;

    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i, vis, adj, st);

    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX)
            for (auto it : adj[node])
            {
                int nd = it.first;
                int d = it.second;

                dist[nd] = min(dist[nd], dist[node] + d);
            }
    }

    for (int i = 0; i < V; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;

    return dist;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> arr{2, 3, 5, 7, 9};
    int k = 100;

    cout << checkSubsequenceSum(arr, k) << endl;

    return 0;
}