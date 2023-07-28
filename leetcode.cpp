// @author Soumya
#include <iostream>
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
void insertAtHead(ListNode *&head, int val)
{
    ListNode *temp = head;

    head = new ListNode(val);
    head->next = temp;
}

// insert node at end
void insertAtEnd(ListNode *&head, int val)
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
void display(ListNode *&head)
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << "-->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right)
        return head;

    ListNode *curr = head, *prev = new ListNode(-1), *nxt;
    prev->next = curr;
    int cnt = 1;

    while (cnt != left)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    while (cnt != right)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }

    return head;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *head = new ListNode(1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    display(head);
    cout << endl;

    ListNode *n = reverseBetween(head, 2, 4);

    display(n);
    cout << endl;

    return 0;
}