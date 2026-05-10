// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

void print(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int maxi = 0;

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] > heights[i]))
        {
            int j = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int right = i;
            int area = (right - left - 1) * heights[j];
            maxi = max(maxi, area);
        }

        st.push(i);
    }

    return maxi;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int maxA = 0;
    vector<vector<int>> matrix2(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        if (i == 0)
            for (int j = 0; j < cols; j++)
                matrix2[i][j] = matrix[i][j] - '0';
        else
            for (int j = 0; j < cols; j++)
                matrix2[i][j] = matrix[i][j] == '0' ? 0 : matrix2[i - 1][j] + 1;

        maxA = max(maxA, largestRectangleArea(matrix2[i]));
    }

    return maxA;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}