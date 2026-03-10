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

int longestConsecutive(vector<int> &arr)
{
    // Your code here
    int n = arr.size(), mxlen = 1;
    unordered_set<int> st;

    for (auto it : arr)
        st.insert(it);

    for (auto it : st)
        if (st.find(it - 1) == st.end())
        {
            // it is the start
            int num = it, ln = 0;

            while (st.find(num) != st.end())
            {
                ln++;
                num++;
            }

            mxlen = max(mxlen, ln);
        }

    return mxlen;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr{1, 9, 3, 10, 4, 20, 2};

    cout << longestConsecutive(arr) << endl;

    return 0;
}
