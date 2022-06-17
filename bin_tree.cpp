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
    int sum = 0;

public:
    int deepestLeavesSum(Node *root)
    {
        int ht = cal_height(root);
        get_sum(root, 1, ht);
        return sum;
    }

    int cal_height(Node *root)
    {
        if (root == NULL)
            return 0;

        return max(cal_height(root->left), cal_height(root->right)) + 1;
    }

    int get_sum(Node *root, int curr, int ht)
    {
        if (root != NULL)
        {
            if (curr == ht)
                sum += root->data;

            get_sum(root->left, curr + 1, ht);
            get_sum(root->right, curr + 1, ht);
        }
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
    root->right = new Node(3);
    /*
      1
     / \
    2   3
    */

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(10);
    root->left->right->left->right = new Node(12);
    /*
        1
       / \
      2   3
     / \
    4   5
    */

    Solution test;
    cout << test.deepestLeavesSum(root) << endl;

    return 0;
}
