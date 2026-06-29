// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <sstream>
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void selectin_sort(vector<int> &vct)
{
    int n = vct.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (vct[i] > vct[j])
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
        int tmp = vct[i];
        int j = i - 1;

        while (j >= 0 && vct[j] > tmp)
        {
            vct[j + 1] = vct[j];
            j--;
        }

        vct[j + 1] = tmp;
    }
}

void recursive_bubble_sort(vector<int> &vct, int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; i++)
        if (vct[i] > vct[i + 1])
            swap(vct[i], vct[i + 1]);

    recursive_bubble_sort(vct, n - 1);
}

void recursive_insertion_sort(vector<int> &vct, int n)
{
    if (n == 1)
        return;

    recursive_insertion_sort(vct, n - 1);

    int tmp = vct[n - 1];
    int i = n - 2;

    while (i >= 0 && vct[i] > tmp)
    {
        vct[i + 1] = vct[i];
        i--;
    }

    vct[i + 1] = tmp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{9, 8, 7, 6, 5, 4, 3, 2, 1};

    print(vct);

    recursive_insertion_sort(vct, vct.size());

    print(vct);

    return 0;
}