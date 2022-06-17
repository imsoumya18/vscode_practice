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

int deepestLeavesSum(Node *root)
{
    int lc = 0, rc = 0;

    if (root->left != NULL)
        lc = deepestLeavesSum(root->left);

    if (root->right != NULL)
        rc = deepestLeavesSum(root->right);

    return max(lc, rc) + 1;
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
