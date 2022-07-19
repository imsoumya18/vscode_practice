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

void printLevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
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

void help(Node *root, vector<int> &to_delete, vector<Node *> &vct)
{
    for (auto i : to_delete)
    {
        if (i == root->data)
        {
            vct.push_back(root->left);
            vct.push_back(root->right);
        }
        if (i == root->left->data)
            root->left = NULL;
        if (i == root->right->data)
            root->right = NULL;
    }
}

vector<Node *> delNodes(Node *root, vector<int> &to_delete)
{
    vector<Node *> vct;

    if (root == NULL)
        return vct;
    else
        vct.push_back(root);

    help(root->left, to_delete, vct);
    help(root->right, to_delete, vct);

    return vct;
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

    vector<int> to_delete{3, 5};

    for (auto i : delNodes(root, to_delete))
    {
        printLevelOrder(i);
        cout << endl
             << endl
             << endl;
    }

    return 0;
}
