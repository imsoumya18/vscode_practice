// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void selection_sort(vector<int> &vct)
{
	int n = vct.size();

	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			if (vct[j] < vct[i])
				swap(vct[i], vct[j]);
}

void bubble_sort(vector<int> &vct)
{
	int n = vct.size();

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (vct[j + 1] < vct[j])
				swap(vct[j], vct[j + 1]);
}

void insertion_sort(vector<int> &vct)
{
	int n = vct.size();

	for (int i = 1; i < n; i++)
	{
		int temp = vct[i];
		int j = i - 1;

		while (j >= 0 && vct[j] > temp)
		{
			vct[j + 1] = vct[j];
			j--;
		}

		vct[j + 1] = temp;
	}
}

void merge(vector<int> &vct, int l, int mid, int r)
{
	vector<int> arr1, arr2;

	for (int i = l; i <= mid; i++)
		arr1.push_back(vct[i]);

	for (int i = mid + 1; i <= r; i++)
		arr2.push_back(vct[i]);

	int i = l, j = 0, k = 0;

	while (j < arr1.size() && k < arr2.size())
	{
		if (arr1[j] < arr2[k])
		{
			vct[i] = arr1[j];
			i++;
			j++;
		}
		else
		{
			vct[i] = arr2[k];
			i++;
			k++;
		}
	}

	while (j < arr1.size())
	{
		vct[i] = arr1[j];
		i++;
		j++;
	}

	while (k < arr2.size())
	{
		vct[i] = arr2[k];
		i++;
		k++;
	}
}

void merge_sort(vector<int> &vct, int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;

		merge_sort(vct, l, mid);
		merge_sort(vct, mid + 1, r);

		merge(vct, l, mid, r);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> vct{5, 4, 3, 2, 1};

	for (auto i : vct)
		cout << i << " ";
	cout << endl;

	merge_sort(vct, 0, 4);

	for (auto i : vct)
		cout << i << " ";
	cout << endl;

	return 0;
}
