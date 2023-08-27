// @author Soumya
#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long minimumPossibleSum(int n, int target)
{
	set<int> st;

	st.insert(1);

	long long ans = 1;
	int it = 2;

	while (st.size() != n)
	{
		if (st.find(target - it) == st.end())
		{
			st.insert(it);
			ans += it;
		}
		it++;
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 2, target = 3;

	cout << minimumPossibleSum(n, target) << endl;

	return 0;
}