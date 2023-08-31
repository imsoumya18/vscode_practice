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

vector<vector<int>> printLevelOrder(TreeNode *root)
{
	vector<vector<int>> vct;
	vector<int> curr;

	if (root == nullptr)
		return vct;

	queue<TreeNode *> q;
	q.push(root);
	q.push(nullptr);

	while (!q.empty())
	{
		TreeNode *node = q.front();
		q.pop();

		if (node != nullptr)
		{
			curr.push_back(node->val);

			if (node->left)
				q.push(node->left);

			if (node->right)
				q.push(node->right);
		}
		else if (!q.empty())
		{
			vct.push_back(curr);
			curr.clear();
			q.push(nullptr);
		}
	}

	vct.push_back(curr);

	return vct;
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

	for (auto i : printLevelOrder(root))
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}