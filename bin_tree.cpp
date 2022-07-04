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

class Solution
{
public:
    bool isMirror(Node *root1, Node *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL && root2 != NULL)
            return false;

        if (root1 != NULL && root2 == NULL)
            return false;

        else
            return ((root1->data == root2->data) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));
    }

    bool isSymmetric(Node *root)
    {
        if (root = NULL)
            return true;

        return isMirror(root->left, root->right);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->right = new Node(3);
    root->right->right = new Node(3);

    Solution s;
    cout << s.isSymmetric(root);

    return 0;
}
