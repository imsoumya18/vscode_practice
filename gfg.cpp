// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
#include <set>
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

vector<int> dijkstra_using_pq(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<vector<pair<int, int>>> adj(V);

    for (auto e : edges)
    {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    minHeap.push({0, src});

    while (!minHeap.empty())
    {
        int node = minHeap.top().second;
        int dis = minHeap.top().first;
        minHeap.pop();

        for (auto it : adj[node])
        {
            int nd = it.first;
            int d = it.second;

            if (dis + d < dist[nd])
            {
                dist[nd] = dis + d;
                minHeap.push({dist[nd], nd});
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;

    return dist;
}

vector<int> dijkstra_using_set(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<vector<pair<int, int>>> adj(V);

    for (auto e : edges)
    {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    set<pair<int, int>> st;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty())
    {
        int dis = st.begin()->first;
        int node = st.begin()->second;
        st.erase(st.begin());

        for (auto it : adj[node])
        {
            int nd = it.first;
            int d = it.second;

            if (dist[node] + d < dist[nd])
            {
                if (dist[nd] != INT_MAX)
                    st.erase({dist[nd], nd});

                dist[nd] = dist[node] + d;
                st.insert({dist[nd], nd});
            }
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