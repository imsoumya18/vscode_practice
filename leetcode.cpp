// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void tst(int x)
{
	cout << x << endl;
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

	for (auto i : tickets)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}