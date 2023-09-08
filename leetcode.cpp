// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> vct;

	vct.push_back(vector<int>{1});

	if (numRows == 1)
		return vct;

	int cnt = 1;

	while (cnt != numRows)
	{
		vector<int> last = vct.back();
		vector<int> newRow{1};

		for (int i = 0; i < last.size() - 1; i++)
			newRow.push_back(last[i] + last[i + 1]);

		newRow.push_back(1);

		vct.push_back(newRow);
		cnt++;
	}

	return vc;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int numRows = 5;

	for (auto i : generate(numRows))
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}