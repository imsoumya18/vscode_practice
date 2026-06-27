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

int search(vector<int> &inorder, int start, int end, int target)
{
    for (int i = 0; i < inorder.size(); i++)
        if (inorder[i] == target)
            return i;
}

TreeNode *realBuildTree(vector<int> &preorder, vector<int> &inorder, int start, int end)
{
    if (start > end)
        return nullptr;

    int idx = 0;
    int curr = preorder[idx];
    idx++;
    TreeNode *node = new TreeNode(curr);

    int pos = search(inorder, start, end, curr);
    node->left = realBuildTree(preorder, inorder, start, pos - 1);
    node->right = realBuildTree(preorder, inorder, pos + 1, end);

    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int start = 0, end = preorder.size();

    return realBuildTree(preorder, inorder, start, end);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}