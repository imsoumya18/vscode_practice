// @author Soumya
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solve(int idx, string s, map<string, bool> &mp, vector<int> &dp)
{
	if (idx >= s.size())
		return 0;

	if (dp[idx] != -1)
		return dp[idx];

	string curr = "";
	int res = s.size();

	for (int i = idx; i < s.size(); i++)
	{
		curr.push_back(s[i]);
		int extra = curr.size();

		if (mp[curr])
			extra = 0;

		extra += solve(i + 1, s, mp, dp);

		res = min(res, extra);
	}

	dp[idx] = res;

	return res;
}

int minExtraChar(string s, vector<string> &dictionary)
{
	map<string, bool> mp;

	for (auto i : dictionary)
		mp[i] = true;

	vector<int> dp(s.size(), -1);

	return solve(0, s, mp, dp);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s = "leetscode";
	vector<string> dictionary{"leet", "code", "leetcode"};

	cout << minExtraChar(s, dictionary) << endl;

	return 0;
}