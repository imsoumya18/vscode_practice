// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(struct TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct TreeNode *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void inorder(struct TreeNode *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int search(int in[], int curr, int start, int end)
{
    for (int i = start; i <= end; i++)
        if (in[i] == curr)
            return i;

    return -1;
}

TreeNode *buildTree(int pre[], int in[], int start, int end)
{
    static int idx = 0;

    if (start > end)
        return nullptr;

    int curr = pre[idx];
    idx++;
    TreeNode *node = new TreeNode(curr);

    if (start == end)
        return node;

    int pos = search(in, curr, start, end);
    node->left = buildTree(pre, in, start, pos - 1);
    node->right = buildTree(pre, in, pos + 1, end);

    return node;
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
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    // cout << "Preorder:" << endl;
    // preorder(root);
    // cout << endl;

    // cout << "Postorder:" << endl;
    // postorder(root);
    // cout << endl;

    // cout << "Inorder:" << endl;
    // inorder(root);
    // cout << endl;

    int pre[] = {1, 2, 4, 5, 6, 7, 3}, in[] = {4, 2, 6, 5, 7, 1, 3};

    TreeNode *n = buildTree(pre, in, 0, 6);

    cout << "Preorder:" << endl;
    preorder(n);
    cout << endl;

    cout << "Inorder:" << endl;
    inorder(n);
    cout << endl;

    return 0;
}