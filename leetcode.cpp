// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data)
	{
		val = data;
		left = nullptr;
		right = nullptr;
	}
};

void printLevelOrder(TreeNode *root)
{
	if (root == nullptr)
		return;

	queue<TreeNode *> q;
	q.push(root);
	q.push(nullptr);

	while (!q.empty())
	{
		TreeNode *node = q.front();
		q.pop();

		if (node != nullptr)
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
			q.push(nullptr);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	struct TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);

	printLevelOrder(root);

	return 0;
}