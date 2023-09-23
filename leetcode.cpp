// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void down(int x)
{
	cout << x << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x = 4;

	down(x);

	return 0;
}
