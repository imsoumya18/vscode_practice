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

int search(int curr, vector<int> &inorder, int start, int end)
{
    int i;
    for (i = start; i <= end; i++)
        if (curr == inorder[i])
            return i;

    return -1;
}

TreeNode *proper(vector<int> &preorder, vector<int> &inorder, int start, int end)
{
    int idx = 0;

    if (start > end)
        return NULL;

    int curr = preorder[idx];
    idx++;
    TreeNode *node = new TreeNode(curr);

    if (start == end)
        return node;

    int pos = search(curr, inorder, start, end);
    node->left = proper(preorder, inorder, start, pos - 1);
    node->right = proper(preorder, inorder, pos + 1, end);

    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return proper(preorder, inorder, 0, inorder.size() - 1);
}

void printLevelOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->val << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            cout << endl;
            q.push(NULL);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    struct TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    printLevelOrder(buildTree(preorder, inorder));

    return 0;
}