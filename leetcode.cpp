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

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    map<TreeNode *, TreeNode *> parent;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node->left)
        {
            parent[node->left] = node;
            q.push(node->left);
        }

        if (node->right)
        {
            parent[node->right] = node;
            q.push(node->right);
        }
    }

    queue<TreeNode *> bfs;
    set<TreeNode *> visited;
    bfs.push(target);
    visited.insert(target);

    int dist = 0;

    while (!bfs.empty())
    {
        int sz = bfs.size();

        if (dist == k)
            break;

        while (sz)
        {
            TreeNode *node = bfs.front();
            bfs.pop();

            if (node->left && !visited.count(node->left))
            {
                bfs.push(node->left);
                visited.insert(node->left);
            }

            if (node->right && !visited.count(node->right))
            {
                bfs.push(node->right);
                visited.insert(node->right);
            }

            if (!visited.count(parent[node]) && parent[node])
            {
                bfs.push(parent[node]);
                visited.insert(parent[node]);
            }

            sz--;
        }

        dist++;
    }

    vector<int> vct;

    while (!bfs.empty())
    {
        vct.push_back(bfs.front()->val);
        bfs.pop();
    }

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}