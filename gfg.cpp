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

void help(Node *root, int r, int c, map<int, pair<int, int>> &mp)
{
    if (!root)
        return;

    if (mp.find(c) == mp.end() || r >= mp[c].first)
    {
        mp[c].first = r;
        mp[c].second = root->data;
    }

    help(root->left, r + 1, c - 1, mp);
    help(root->right, r + 1, c + 1, mp);
}

vector<int> bottomView(Node *root)
{
    // code here
    map<int, pair<int, int>> mp;
    int r = 0, c = 0;

    help(root, r, c, mp);

    vector<int> vct;

    for (const auto &col : mp)
        vct.push_back(col.second.second);

    return vct;
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

    map<int, map<int, multiset<int>>> mp;
    mp[1] = -1;
    mp[2] = -2;

    for (auto it : mp)
        cout << it.first << it.second << endl;

    return 0;
}