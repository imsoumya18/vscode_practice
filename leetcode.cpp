// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<string> findItinerary(vector<vector<string>> &tickets)
{
	vector<string> ans;
	// set<string> src, dest;

	// for (auto i : tickets)
	// {
	// 	src.insert(i[0]);
	// 	dest.insert(i[1]);
	// }

	// for (auto i : src)
	// {
	// 	int flag = 0;
	// 	for (auto j : dest)
	// 		if (i == j)
	// 		{
	// 			flag = 1;
	// 			break;
	// 		}

	// 	if (flag == 0)
	// 	{
	// 		ans.push_back(i);
	// 		break;
	// 	}
	// }

	// if (ans.empty())
	// 	ans.push_back(tickets[0][0]);

	ans.push_back("JFK");

	// for (auto i : ans)
	// 	cout << i << " ";

	// cout << "test" << endl;

	while (!tickets.empty())
	{
		int min_idx = -1;
		string start = ans.back();

		for (int i = 0; i < tickets.size(); i++)
			if (tickets[i][0] == start)
			{
				if (min_idx == -1)
					min_idx = i;

				if (tickets[i][1] < tickets[min_idx][1])
					min_idx = i;
			}

		ans.push_back(tickets[min_idx][1]);
		tickets.erase(tickets.begin() + min_idx);
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<string>> tickets{
		{"JFK", "KUL"},
		{"JFK", "NRT"},
		{"NRT", "JFK"}};

	for (auto i : findItinerary(tickets))
		cout << i << " ";

	return 0;
}