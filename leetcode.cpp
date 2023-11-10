// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
	int lo = 0, hi = arr.size() - 1;
	int mid = lo + (hi - lo) / 2;

	while (lo < hi)
	{
		if (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])
			hi = mid;
		else if (mid == 0 || arr[mid] > arr[mid - 1])
			lo = mid + 1;

		mid = lo + (hi - lo) / 2;
	}

	return mid;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr{0, 1, 0};
	int target = 8;

	cout << peakIndexInMountainArray(arr) << endl;

	return 0;
}
