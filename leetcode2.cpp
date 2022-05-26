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

vector<int> rightSideView(TreeNode *root)
{
    int i;
    vector<int> vct;
    if (root == NULL)
        return vct;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node != NULL)
        {
            i = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            vct.push_back(i);
            q.push(NULL);
        }
    }
    vct.push_back(i);

    return vct;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{1, 2, 3, 4};

    for (auto i : productExceptSelf(nums))
        cout << i << " ";

    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // printLevelOrder(root);

    // for (auto i : rightSideView(root))
    //     cout << i << " ";

    return 0;
}