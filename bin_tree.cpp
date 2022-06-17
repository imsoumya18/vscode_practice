// @author Soumya
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int cal_height(Node *root)
{
    int lc = 0, rc = 0;

    if (root->left != NULL)
        lc = cal_height(root->left);

    if (root->right != NULL)
        rc = cal_height(root->right);

    return max(lc, rc) + 1;
}

int deepestLeavesSum(Node *root)
{
    int ht = cal_height(root), ls = 0, rs = 0, i = 1;

    while (root->left != NULL)
    {
        root = root->left;
        i++;
    }
    if (i == ht)
        ls = root->data;

    i = 1;
    while (root->right != NULL)
    {
        root = root->right;
        i++;
    }
    if (i == ht)
        rs = root->data;

    return ls + rs;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    /*
      1
     / \
    2   3
    */

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(10);
    root->left->right->left->right = new Node(12);
    /*
        1
       / \
      2   3
     / \
    4   5
    */

    cout << deepestLeavesSum(root);

    return 0;
}
