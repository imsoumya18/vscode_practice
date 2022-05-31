// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> printLevelOrder(TreeNode *root)
{
    vector<vector<int>> vct;
    if (root == NULL)
        return vct;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        vector<int> temp;
        TreeNode *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->val << " ";
            temp.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            vct.push_back(temp);
            cout << endl;
            q.push(NULL);
        }

        return vct;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> vct;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vct = printLevelOrder(root);

    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}