// @author Soumya
#include <iostream>
#include <queue>
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

// level order traversal
int count_nodes(Node *root)
{
    if (root == NULL)
        return 0;

    return count_nodes(root->left) + count_nodes(root->right) + root->data;
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
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    /*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
    */

    cout << count_nodes(root);

    return 0;
}
