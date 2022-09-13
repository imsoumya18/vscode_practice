// @author Soumya
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void insert(vector<int> &vct, TreeNode *root)
{
    if (root == NULL)
        return;

    int i;
    for (i = 0; i < vct.size(); i++)
        if (vct[i] > root->val)
            break;

    vct.insert(vct.begin() + i, root->val);

    if (root->left != NULL)
        insert(vct, root->left);
    if (root->right != NULL)
        insert(vct, root->right);
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

vector<int> inorder_iterative(TreeNode *root)
{
    vector<int> vct;
    stack<TreeNode *> st;
    TreeNode *node = root;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            vct.push_back(node->val);
            node = node->right;
        }
    }

    return vct;
}

vector<int> preorder_iterative(TreeNode *root)
{
    vector<int> vct;

    if (root == NULL)
        return vct;

    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        vct.push_back(root->val);

        if (root->right)
            st.push(root->right);

        if (root->left)
            st.push(root->left);
    }

    return vct;
}

vector<int> postorder_iterative(TreeNode *root)
{
    vector<int> vct;

    if (root == NULL)
        return vct;

    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        vct.push_back(root->val);

        if (root->left)
            st.push(root->left);

        if (root->right)
            st.push(root->right);
    }

    return vct;
}

void helper(vector<TreeNode *> &vct, TreeNode *root, int n)
{
    if (n < 2)
    {
        vct.push_back(root);
        return;
    }

    if (!root->left && !root->right)
    {
        root->left = new TreeNode(0);
        root->right = new TreeNode(0);
        helper(vct, root->left, n - 2);
    }
}

vector<TreeNode *> allPossibleFBT(int n)
{
    vector<TreeNode *> vct;
    TreeNode *root = new TreeNode(0);
    n--;
    helper(vct, root, n);
    return vct;
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

    int n = 5;

    cout << allPossibleFBT(n).size() << endl;

    return 0;
}
