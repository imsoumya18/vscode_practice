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

vector<int> rightSideView(TreeNode *root)
{
    int i;
    vector<int> vct;
    if (root == NULL)
        return vct;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node != NULL)
        {
            i = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            vct.push_back(i);
            q.push(NULL);
        }
    }
    vct.push_back(i);

    return vct;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> vct(nums.size());
    int pre = 1, post = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        vct[i] = pre;
        pre *= nums[i];
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        vct[i] *= post;
        post *= nums[i];
    }

    return vct;
}

string intToRoman(int num)
{
    string s = "";

    while (num >= 1000)
    {
        s += "M";
        num -= 1000;
    }

    while (num >= 900)
    {
        s += "CM";
        num -= 900;
    }

    while (num >= 500)
    {
        s += "D";
        num -= 500;
    }

    while (num >= 400)
    {
        s += "CD";
        num -= 400;
    }

    while (num >= 100)
    {
        s += "C";
        num -= 100;
    }

    while (num >= 90)
    {
        s += "XC";
        num -= 90;
    }

    while (num >= 50)
    {
        s += "L";
        num -= 50;
    }

    while (num >= 40)
    {
        s += "XL";
        num -= 40;
    }

    while (num >= 10)
    {
        s += "X";
        num -= 10;
    }

    while (num >= 9)
    {
        s += "IX";
        num -= 9;
    }

    while (num >= 5)
    {
        s += "V";
        num -= 5;
    }

    while (num >= 4)
    {
        s += "IV";
        num -= 4;
    }

    while (num >= 1)
    {
        s += "I";
        num -= 1;
    }

    return s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums{1, 2, 3, 4};

    // for (auto i : productExceptSelf(nums))
    //     cout << i << " ";

    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // printLevelOrder(root);

    // for (auto i : rightSideView(root))
    //     cout << i << " ";

    int num = 9;

    cout << intToRoman(num) << endl;

    return 0;
}