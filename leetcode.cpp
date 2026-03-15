// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void print1d(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";

    cout << endl;
}

void print2d(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

class node
{
public:
    int val;
    node *next;

    node(int x)
    {
        val = x;
        next = nullptr;
    }
};

void insertAtEnd(node *&head, int x)
{
    if (head == nullptr)
    {
        head = new node(x);
        return;
    }

    node *curr = head;

    while (curr->next)
        curr = curr->next;

    curr->next = new node(x);
}

void printList(node *head)
{
    node *curr = head;

    while (curr)
    {
        cout << curr->val << "-->";
        curr = curr->next;
    }

    cout << "NULL" << endl;
}

void rotate(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < i; j++)
            if (i != j)
                swap(matrix[i][j], matrix[j][i]);

    for (int i = 0; i < rows; i++) {
        int l = 0, r = cols - 1;

        while (l < r) {
            swap(matrix[i][l], matrix[i][r]);
            l++;
            r--;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    print2d(matrix);

    rotate(matrix);

    print2d(matrix);

    return 0;
}
