// @author Soumya
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// linked list implementation
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

// insert node at end
void insertAtEnd(ListNode *&head, int val)
{
    ListNode *n = new ListNode(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    ListNode *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

// print elements of linked list
void display(ListNode *head)
{
    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

ListNode *removeElements(ListNode *head, int val)
{
    if (head == NULL)
        return NULL;

    head->next = removeElements(head->next, val);

    if (head->val == val)
        return head->next;

    return head;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *list = new ListNode(7);
    insertAtEnd(list, 7);
    insertAtEnd(list, 7);
    insertAtEnd(list, 7);

    int val = 7;

    display(list);
    display(removeElements(list, val));

    return 0;
}