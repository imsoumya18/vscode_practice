// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
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

bool check(vector<int> &arr, int idx, int n, int sum, int k)
{
    if (sum < 0)
        return false;

    if (idx == n)
    {
        if (sum == 0)
            return true;

        return false;
    }

    if (sum == 0)
        return true;

    if (check(arr, idx + 1, n, sum, k))
        return true;

    if (check(arr, idx + 1, n, sum - arr[idx], k))
        return true;

    return false;
}

bool checkSubsequenceSum(vector<int> &arr, int k)
{
    // Code here
    int idx = 0, n = arr.size(), sum = k;

    return check(arr, idx, n, sum, k);
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

    vector<int> arr{2, 3, 5, 7, 9};
    int k = 100;

    cout << checkSubsequenceSum(arr, k) << endl;

    return 0;
}