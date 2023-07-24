// @author Soumya
#include <iostream>
#include <set>
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

ListNode *detectCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    ListNode *slow = head, *fast = head;

    while (slow != nullptr && fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
            fast = fast->next;

        slow = slow->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return nullptr;

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    while (slow->next != fast)
        slow = slow->next;

    slow->next = nullptr;
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
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);
    insertAtEnd(head, 9);

    display(head);
    cout << detectCycle(head)->val << endl;

    return 0;
}