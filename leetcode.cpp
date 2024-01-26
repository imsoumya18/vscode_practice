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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> vct{1, 2, 3}, vct2{1, 2, 3};

	cout << (vct == vct2) << endl;

	return 0;
}
