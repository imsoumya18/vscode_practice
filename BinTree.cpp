// @author Soumya
#include <iostream>
#include <vector>
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

int search(vector<int> inorder, int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
        if (inorder[i] == curr)
            return i;

    return -1;
}

Node *buildTree(vector<int> preorder, vector<int> inorder, int start, int end)
{
    static int idx = 0;

    if (start > end)
        return NULL;

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);

    if (start == end)
        return node;

    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

Node *buildTree2(vector<int> postorder, vector<int> inorder, int start, int end)
{
    static int idx = postorder.size() - 1;

    if (start > end)
        return NULL;

    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr);

    if (start == end)
        return node;

    int pos = search(inorder, start, end, curr);
    node->right = buildTree2(postorder, inorder, pos + 1, end);
    node->left = buildTree2(postorder, inorder, start, pos - 1);

    return node;
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
