// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
#include <set>
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

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void floydWarshall(vector<vector<int>> &dist)
{
    // Code here
    int n = dist.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                dist[i][j] = 0;
            else if (dist[i][j] == -1)
                dist[i][j] = INT_MAX;

    for (int via = 0; via < n; via++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX && dist[i][via] + dist[via][j] < dist[i][j])
                    dist[i][j] = dist[i][via] + dist[via][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][j] == INT_MAX)
                dist[i][j] = -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    print(primeFactors(13));

    return 0;
}