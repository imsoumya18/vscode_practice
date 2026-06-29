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

int minTime(Node *root, int target)
{
    // code here
    map<Node *, Node *> parent;
    queue<Node *> q;
    q.push(root);
    Node *targetNode;

    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();

        if (n->data == target)
            targetNode = n;

        if (n->left)
        {
            parent[n->left] = n;
            q.push(n->left);
        }

        if (n->right)
        {
            parent[n->right] = n;
            q.push(n->right);
        }
    }

    int t = 0;
    queue<Node *> bfs;
    set<Node *> vis;
    bfs.push(targetNode);
    vis.insert(targetNode);

    while (!bfs.empty())
    {
        int sz = bfs.size();

        while (sz--)
        {
            Node *n = bfs.front();
            bfs.pop();

            if (n->left && !vis.count(n->left))
            {
                bfs.push(n->left);
                vis.insert(n->left);
            }

            if (n->right && !vis.count(n->right))
            {
                bfs.push(n->right);
                vis.insert(n->right);
            }

            if (parent[n] && !vis.count(parent[n]))
            {
                bfs.push(parent[n]);
                vis.insert(parent[n]);
            }
        }

        if (!bfs.empty())
            t++;
    }

    return t;
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

    return 0;
}