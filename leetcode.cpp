// @author Soumya
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
{
	if (sx == fx && sy == fy && t == 1)
		return false;

	int mindis = max(abs(fx - sx), abs(fy - sy));

	if (mindis > t)
		return false;

	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int sx = 3, sy = 1, fx = 7, fy = 3, t = 3;

	cout << isReachableAtTime(sx, sy, fx, fy, t) << endl;

	return 0;
}