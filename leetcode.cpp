// @author Soumya
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> groupThePeople(vector<int> &groupSizes)
{
	vector<vector<int>> ans;

	for (int i = 0; i < groupSizes.size(); i++)
	{
		int ele = i;
		int grpsize = groupSizes[i];
		int flag = 0;

		for (auto j : ans)
			if (j.size() == grpsize && j.back() == -1)
			{
				flag = 1;
				int k = 0;
				while (j[k] != -1)
					k++;
				j[k] = ele;
				break;
			}

		if (flag == 0 || ans.size() == 0)
		{
			vector<int> temp(grpsize, -1);
			temp[0] = ele;
			ans.push_back(temp);
		}
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> groupSizes{3, 3, 3, 3, 3, 1, 3};

	for (auto i : groupThePeople(groupSizes))
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}