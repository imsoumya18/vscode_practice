// @author Soumya
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int minimumOperations(string num)
{
	int n = num.size();

	int it = n - 1, cnt = 0;

	while (it >= 0 && num[it] != '0' && num[it] != '5')
	{
		it--;
		cnt++;
	}
	cnt--;

	if (num[it] == '0')
	{
		num[it] = 'X';
		while (it >= 0 && num[it] != '0' && num[it] != '5')
		{
			it--;
			cnt++;
		}
	}
	else if (num[it] == '5')
	{
		while (it >= 0 && num[it] != '2' && num[it] != '7')
		{
			it--;
			cnt++;
		}
	}

	return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string num = "2908305";

	cout << minimumOperations(num) << endl;

	return 0;
}