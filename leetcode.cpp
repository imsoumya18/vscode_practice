// @author Soumya
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
	vector<string> ans;

	int i = 0, it = 1;

	while (i < target.size())
	{
		ans.push_back("Push");

		if (target[i] == it)
			i++;
		else
			ans.push_back("Pop");

		it++;
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> target{1, 2, 3};
	int n = 3;

	for (auto i : buildArray(target, n))
		cout << i << " ";

	return 0;
}