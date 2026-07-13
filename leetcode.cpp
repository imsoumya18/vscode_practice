// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <sstream>
#include <set>
#include <unordered_set>
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (auto e : edges)
    {
        dist[e[0]][e[1]] = e[2];
        dist[e[1]][e[0]] = e[2];
    }

    for (int via = 0; via < n; via++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX && dist[i][via] + dist[via][j] < dist[i][j])
                    dist[i][j] = dist[i][via] + dist[via][j];

    vector<int> neighbour(n, 0);
    int city_with_max_neighbour = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i != j && dist[i][j] <= distanceThreshold)
                neighbour[i]++;

        if (neighbour[i] <= neighbour[city_with_max_neighbour])
            city_with_max_neighbour = i;
    }

    return city_with_max_neighbour;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}