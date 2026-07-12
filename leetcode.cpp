// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <sstream>
#include <set>
#include <unordered_set>
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class DisJointSet
{
    vector<int> rank, parent;

public:
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findUltParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findUltParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);

        if (ulp_u == ulp_v)
            return;
        else if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}