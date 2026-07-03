// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <sstream>
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countPaths(int n, vector<vector<int>> &roads)
{
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> adj(n);

    for (auto road : roads)
    {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
    vector<long long> dist(n, LLONG_MAX), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    minHeap.push({0, 0});

    while (!minHeap.empty())
    {
        long long dis = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();

        if (dis > dist[node])
            continue;

        for (auto it : adj[node])
        {
            int nd = it.first;
            long long d = it.second;

            if (dis + d < dist[nd])
            {
                dist[nd] = dis + d;
                minHeap.push({dist[nd], nd});
                ways[nd] = ways[node];
            }
            else if (dis + d == dist[nd])
                ways[nd] = (ways[nd] + ways[node]) % MOD;
        }
    }

    return ways[n - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    cout << minimumEffortPath(heights) << endl;

    return 0;
}