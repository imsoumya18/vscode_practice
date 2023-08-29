// @author Soumya
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int bestClosingTime(string customers)
{
	vector<int> y, n;
	int curry = 0, currn = 0;
	int val = INT32_MAX, idx = 0;

	for (int i = 0; i < customers.size(); i++)
	{
		y.push_back(curry);
		n.push_back(currn);

		if (customers[i] == 'Y')
			curry++;
		else
			currn++;
	}

	y.push_back(curry);
	n.push_back(currn);

	for (int i = 0; i <= customers.size(); i++)
	{
		int curr = n[i] + (curry - y[i]);

		if (curr < val)
		{
			val = curr;
			idx = i;
		}
	}

	// for (auto i : y)
	// 	cout << i << " ";
	// cout << endl;

	// for (auto i : n)
	// 	cout << i << " ";
	// cout << endl;

	return idx;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string customers = "YYYY";

	cout << bestClosingTime(customers) << endl;

	return 0;
}