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

TreeNode *helper(TreeNode *root)
{
    if (!root->left)
        return root->right;

    if (!root->right)
        return root->left;

    TreeNode *lNode = root->left;
    TreeNode *rNode = root->right;

    while (lNode->right)
        lNode = lNode->right;

    lNode->right = rNode;

    return root->left;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;

    if (root->val == key)
        return helper(root);

    TreeNode *curr = root;

    while (curr)
        if (key < curr->val)
        {
            if (curr->left && curr->left->val == key)
            {
                curr->left = helper(curr->left);
                break;
            }
            else
                curr = curr->left;
        }
        else
        {
            if (curr->right && curr->right->val == key)
            {
                curr->right = helper(curr->right);
                break;
            }
            else
                curr = curr->right;
        }

    return root;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}