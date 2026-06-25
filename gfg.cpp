// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

void print(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool isLeaf(Node *root)
{
    return root && !root->left && !root->right;
}

void leftTraversal(Node *root, vector<int> &vct)
{
    Node *curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr))
            vct.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void leafTraversal(Node *root, vector<int> &vct)
{
    if (isLeaf(root))
    {
        vct.push_back(root->data);
        return;
    }

    if (root->left)
        leafTraversal(root->left, vct);
    if (root->right)
        leafTraversal(root->right, vct);
}

void rightTraversal(Node *root, vector<int> &vct)
{
    stack<int> st;
    Node *curr = root->right;

    while (curr)
    {
        if (!isLeaf(curr))
            st.push(curr->data);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    while (!st.empty())
    {
        vct.push_back(st.top());
        st.pop();
    }
}

vector<int> boundaryTraversal(Node *root)
{
    // code here
    vector<int> vct;

    if (!root)
        return vct;

    if (!isLeaf(root))
        vct.push_back(root->data);

    leftTraversal(root, vct);
    leafTraversal(root, vct);
    rightTraversal(root, vct);

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    print(boundaryTraversal(root));

    return 0;
}