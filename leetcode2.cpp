// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->val << " ";
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

bool exist(vector<vector<char>> &board, string word)
{
    int i = 0, j = 0, k, p, q;

    for (i = 0; i < board.size(); i++)
        for (j = 0; j < board[0].size(); j++)
            if (board[i][j] == word[0])
            {
                p=i;
                q=j;
                k=0;
                while(p<board.size() && q<board[0].size()){}
            }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";

    cout << exist(board, word) << endl;

    return 0;
}