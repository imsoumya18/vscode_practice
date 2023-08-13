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

ListNode *revList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *curr = head, *prev = nullptr, *nxt;

    while (curr != nullptr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

ListNode *doubleIt(ListNode *head)
{
    ListNode *n = revList(head);
    // display(n);

    int dbl = 0, carry = 0;

    ListNode *curr = n;

    while (curr != nullptr)
    {
        dbl = 2 * curr->val + carry;

        if (dbl >= 10)
        {
            carry = dbl / 10;
            curr->val = dbl % 10;
        }
        else
        {
            curr->val = dbl;
            carry = 0;
        }

        curr = curr->next;
    }

    if (carry != 0)
        insertAtEnd(n, carry);

    // display(n);

    return revList(n);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *head = new ListNode(9);
    insertAtEnd(head, 9);
    insertAtEnd(head, 9);

    display(head);

    ListNode *n = doubleIt(head);

    display(n);

    return 0;
}