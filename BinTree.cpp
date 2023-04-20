// @author Soumya
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int calHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

int calDiameter(Node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
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

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    cout << "Height of the tree: " << calHeight(root) << endl;
    cout << "Diameter of the tree: " << calDiameter(root) << endl;

    return 0;
}
