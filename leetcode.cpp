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

int countSubstring(string s)
{
    // Code here
    int n = s.size(), lastA = -1, lastB = -1, lastC = -1, ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            lastA = i;
        else if (s[i] == 'b')
            lastB = i;
        else
            lastC = i;

        if (lastA != -1 && lastB != -1 && lastC != -1)
            ans += (min({lastA, lastB, lastC}) + 1);
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s = "abcabc";

    cout << countSubstring(s) << endl;

    return 0;
}
