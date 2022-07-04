// @author Soumya
#include <iostream>
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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *lst = new ListNode();
    ListNode *temp = lst;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            temp->next = new ListNode(list1->val);
            temp = temp->next;
            list1 = list1->next;
        }
        else
        {
            temp->next = new ListNode(list2->val);
            temp = temp->next;
            list2 = list2->next;
        }
    }

    while (list1 != NULL)
    {
        temp->next = new ListNode(list1->val);
        temp = temp->next;
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        temp->next = new ListNode(list2->val);
        temp = temp->next;
        list2 = list2->next;
    }

    return lst->next;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL, *nxt = NULL;
    while (head != NULL)
    {
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = head, *temp2 = head->next;

    while (head != NULL && head->next != NULL)
    {
        ListNode *t = head->next, *prev;
        head->next = t->next;
        t->next = head;
        if (temp != head)
            prev->next = t;
        prev = head;
        head = head->next;
    }

    return temp2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *list1 = new ListNode(1);
    insertAtEnd(list1, 2);
    insertAtEnd(list1, 3);
    insertAtEnd(list1, 4);
    insertAtEnd(list1, 5);

    ListNode *list2 = new ListNode(1);
    insertAtEnd(list2, 3);
    insertAtEnd(list2, 4);

    display(swapPairs(list1));

    return 0;
}