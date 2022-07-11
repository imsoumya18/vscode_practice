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

bool flipEquiv(Node *root1, Node *root2)
{
    if (root1 == root2)
        return true;

    if (root1 == NULL || root2 == NULL || root1->data != root2->data)
        return false;
    return ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    struct Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(8);
    root1->right->left = new Node(6);

    struct Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->left->right = new Node(6);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);
    root2->right->right->left = new Node(8);
    root2->right->right->right = new Node(7);

    cout << flipEquiv(root1, root2) << endl;

    return 0;
}
