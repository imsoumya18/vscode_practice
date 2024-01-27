// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void print1d(vector<int> vct)
{
	for (auto i : vct)
		cout << i << " ";

	cout << endl;
}

void print2d(vector<vector<int>> vct)
{
	for (auto i : vct)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
}

void help(vector<int> &nums, int l, int r)
{
	while (l < r)
	{
		swap(nums[l], nums[r]);
		l++;
		r--;
	}
}

void rotate(vector<int> &nums, int k)
{
	help(nums, 0, nums.size() - k - 1);
	help(nums, nums.size() - k, nums.size() - 1);
	help(nums, 0, nums.size() - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> vct{1, 2, 3, 4, 5, 6, 7};
	int k = 3;

	print1d(vct);
	rotate(vct, k);
	print1d(vct);

	return 0;
}
