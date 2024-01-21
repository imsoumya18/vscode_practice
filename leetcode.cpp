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

int nCr(int n, int r)
{
	int res = 1;

	for (int i = 0; i < r; i++)
	{
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> vct{};

	for (int row = 1; row <= numRows; row++)
	{
		int res = 1;

		vector<int> temp{};

		temp.push_back(res);

		for (int col = 1; col < row; col++)
		{
			res *= (row - col);
			res /= col;

			temp.push_back(res);
		}

		vct.push_back(temp);
	}

	return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int numRows = 5;

	vector<vector<int>> vct = generate(numRows);

	print2d(vct);

	return 0;
}
