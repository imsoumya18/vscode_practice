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

string reverseWords(string s)
{
    int n = s.size(), readIdx = 0, writeIdx = 0;

    while (readIdx < n && s[readIdx] == ' ')
        readIdx++;

    while (readIdx < n)
        if (s[readIdx] != ' ')
            s[writeIdx++] = s[readIdx++];
        else if (writeIdx > 0 && s[readIdx - 1] != ' ')
        {
            s[writeIdx++] = ' ';
            readIdx++;
        }
        else
            readIdx++;
    
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    node *head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    printList(head);

    cout << getCount(head) << endl;

    return 0;
}
