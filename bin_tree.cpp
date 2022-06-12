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

void deepestLeavesSum(Node *root)
{
    if (root == NULL)
    {
        cout << root->data << endl;
        return;
    }
    deepestLeavesSum(root->left);
    deepestLeavesSum(root->right);
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
    /*
        1
       / \
      2   3
     / \
    4   5
    */

    deepestLeavesSum(root);

    return 0;
}
