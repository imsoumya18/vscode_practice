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

ListNode *findKthNode(ListNode *head, int k)
{
    int cnt = 1;

    while (head && cnt < k)
    {
        head = head->next;
        cnt++;
    }

    return head;
}

ListNode *reverseLL(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *newHead = reverseLL(head->next);
    ListNode *nextHead = head->next;

    nextHead->next = head;
    head->next = nullptr;

    return newHead;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head, *prevNode = nullptr;

    while (temp)
    {
        ListNode *kthNode = findKthNode(temp, k);

        if (kthNode == nullptr)
        {
            if (prevNode)
                prevNode->next = temp;

            break;
        }

        ListNode *nextNode = kthNode->next;
        kthNode->next = nullptr;

        reverseLL(temp);

        if (temp == head)
            head = kthNode;
        else
            prevNode = kthNode;

        prevNode = temp;
        temp = nextNode;
    }

    return head;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr{2, 3, 4, 5, 6};

    cout << inversionCount(arr) << endl;

    return 0;
}
