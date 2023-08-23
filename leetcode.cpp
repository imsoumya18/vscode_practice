// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insert(stack<int> &st, int x)
{
	if (st.empty() || st.top() <= x)
	{
		st.push(x);
		return;
	}

	int temp = st.top();
	st.pop();
	insert(st, x);
	st.push(temp);
}

void sort(stack<int> &st)
{
	if (st.size() == 1)
		return;

	int temp = st.top();
	st.pop();
	sort(st);
	insert(st, temp);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stack<int> st;

	st.push(12);
	st.push(8);
	st.push(3);
	st.push(2);
	st.push(1);

	sort(st);
	// insert(st, 6);

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}

	return 0;
}