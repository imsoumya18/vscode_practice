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
    bool isSame(Node *root1, Node *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;

        else if (root1 == NULL && root2 != NULL)
            return false;

        else if (root1 != NULL && root2 == NULL)
            return false;

        return ((root1->data == root2->data) && isSame(root1->left, root2->left) && isSame(root1->right, root2->right));
    }

    bool isSubtree(Node *root, Node *subRoot)
    {
        if (root == NULL)
            return false;

        if (isSame(root, subRoot))
            return true;

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    struct Node *root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    /*
    3
   / \
  4   5
 / \
1   2
*/

    struct Node *subRoot = new Node(4);
    subRoot->left = new Node(1);
    subRoot->right = new Node(2);

    struct Node *temp = new Node(4);
    temp->left = new Node(1);
    temp->right = new Node(2);

    Solution test;
    cout << test.isSubtree(root, subRoot) << endl;

    return 0;
}
