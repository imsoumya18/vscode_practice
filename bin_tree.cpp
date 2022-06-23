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

class Solution
{
public:
    bool isSubtree(Node *root, Node *subRoot) {}
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

    Solution test;
    cout << test.isSubtree(root, subRoot) << endl;

    return 0;
}
