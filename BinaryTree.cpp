// @author Soumya
#include <iostream>
using namespace std;

struct TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int calHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

int calDiameter(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    int curr = lHeight + rHeight + 1;
    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);

    return max(curr, max(lDiameter, rDiameter));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    // preorder(root);
    // cout << endl;

    // inorder(root);
    // cout << endl;

    // postorder(root);
    // cout << endl;

    cout << calHeight(root) << endl;

    cout << calDiameter(root) << endl;

    return 0;
}