// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> &heights)
{
	stack<int> st;
	st.push(-1);

	int n = heights.size();
	vector<int> ans(n, -1);

	for (int i = 0; i < n; i++)
	{
		while (st.top() != -1 && heights[st.top()] >= heights[i])
			st.pop();
		ans[i] = st.top();
		st.push(i);
	}

	return ans;
}

vector<int> nextSmaller(vector<int> &heights)
{
	stack<int> st;
	st.push(-1);

	int n = heights.size();
	vector<int> ans(n, -1);

	for (int i = n - 1; i >= 0; i--)
	{
		while (st.top() != -1 && heights[st.top()] >= heights[i])
			st.pop();
		ans[i] = st.top();
		st.push(i);
	}

	return ans;
}

int largestRectangleArea(vector<int> &heights)
{
	vector<int> prev = prevSmaller(heights);
	vector<int> next = nextSmaller(heights);

	int ans = 0;
	int n = heights.size();

	for (int i = 0; i < n; i++)
	{
		int l = heights[i];
		if (next[i] == -1)
			next[i] = n;
		int b = next[i] - prev[i] - 1;
		int area = l * b;

		if (area > ans)
			ans = area;
	}

	return ans;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
	int ans = 0;
	vector<int> heights(matrix[0].size(), 0);

	for (auto row : matrix)
	{
		for (int i = 0; i < matrix[0].size(); i++)
			if (row[i] == '0')
				heights[i] = 0;
			else
				heights[i]++;

		ans = max(ans, largestRectangleArea(heights));
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<char>> matrix{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}};

	cout << maximalRectangle(matrix) << endl;

	return 0;
}