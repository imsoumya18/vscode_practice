// @author Soumya
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int myAtoi(string s)
{
	int it = 0;

	while (s[it] == ' ')
		it++;

	while (s[it] != '-' && !(s[it] >= '0' && s[it] <= '9'))
		it++;

	int start = it;

	if (s[it] == '-')
		it++;

	while (s[it] >= '0' && s[it] <= '9' && it < s.size())
		it++;

	int end = it;

	s = s.substr(start, end - start);

	int mult = 1;

	if (s[0] == '-')
	{
		mult = -1;
		s = s.substr(1);
	}
	else if (s[0] == '+')
	{
		mult = 1;
		s = s.substr(1);
	}

	int ans = 0;

	for (auto i : s)
	{
		int dig = i - '0';
		ans = ans * 10;
		ans = ans + dig;
	}

	ans = ans * mult;

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s = "    csahsahsabc +123456789    ubudnjdcnj";

	cout << myAtoi(s) << endl;

	return 0;
}