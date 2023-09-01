// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n)
{
	vector<int> vct(n + 1, 0);

	for (int i = 1; i <= n; i++)
		if (i % 2 == 0)
			vct[i] = vct[i / 2];
		else
			vct[i] = vct[i / 2] + 1;

	return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 5;

	for (auto i : countBits(n))
		cout << i << endl;

	return 0;
}