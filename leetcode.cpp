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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    int flag = 0;
    vector<vector<int>> vct;
    vector<int> line;

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node)
        {
            if (flag % 2 == 0)
                line.push_back(node->val);
            else
                line.insert(line.begin(), node->val);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        else
        {
            flag++;
            vct.push_back(line);
            line.clear();

            if (!q.empty())
                q.push(nullptr);
        }
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