// @author Soumya
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// insert node in BST
Node *insertBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// inorder traversal (left-node-right)
Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key == root->data)
        return root;

    if (key < root->data)
        return searchInBST(root->left, key);

    return searchInBST(root->right, key);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    if (searchInBST(root, 3) == NULL)
        cout << "Key doesn't exist" << endl;
    else
        cout << "Key exists" << endl;

    return 0;
}