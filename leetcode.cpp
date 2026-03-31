// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// linked list implementation
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

// insert node at head
void insertAtHead(ListNode *head, int val)
{
    ListNode *temp = head;

    head = new ListNode(val);
    head->next = temp;
}

// insert node at end
void insertAtEnd(ListNode *head, int val)
{
    ListNode *n = new ListNode(val);

    if (head == nullptr)
    {
        head = n;
        return;
    }

    ListNode *temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = n;
}

// print elements of linked list
void display(ListNode *head)
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << "-->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next)
        return head;

    int length = 1;
    ListNode *tail = head;

    while (tail->next)
    {
        tail = tail->next;
        length++;
    }

    ListNode *newTail = head;
    k = k % length;

    if (k == 0)
        return head;

    for (int i = 0; i < length - k - 1; i++)
        newTail = newTail->next;

    ListNode *newHead = newTail->next;
    tail->next = head;
    newTail->next = nullptr;

    return newHead;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *head = new ListNode(1);
    insertAtEnd(head, 2);

    display(head);

    return 0;
}