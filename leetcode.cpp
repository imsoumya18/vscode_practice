// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	int col0 = 1;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;

				if (j == 0)
					col0 = 0;
				else
					matrix[0][j] = 0;
			}
		}

	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}

	if (matrix[0][0] == 0)
		for (int j = 0; j < n; j++)
			matrix[0][j] = 0;

	if (col0 == 0)
		for (int i = 0; i < m; i++)
			matrix[i][0] = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, ans;

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	cout << endl
		 << endl;

	setZeroes(matrix);

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	return 0;
}
