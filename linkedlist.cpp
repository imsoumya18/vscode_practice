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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int n1 = 0, n2 = 0, sum, carry = 0;

    n1 = l1->val;
    n2 = l2->val;

    sum = n1 + n2 + carry;
    if (sum > 9)
    {
        carry = sum / 10;
        sum %= 10;
    }
    ListNode *list = new ListNode(sum);
    ListNode *curr = list;
    l1 = l1->next;
    l2 = l2->next;

    while (l1 != NULL || l2 != NULL)
    {
        if (l1 == NULL)
            n1 = 0;
        else
            n1 = l1->val;

        if (l2 == NULL)
            n2 = 0;
        else
            n2 = l2->val;

        sum = n1 + n2 + carry;
        if (sum > 9)
        {
            carry = sum / 10;
            sum %= 10;
        }
        else
            carry = 0;

        ListNode *temp = new ListNode(sum);
        curr->next = temp;
        curr = curr->next;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }
    if (carry > 0)
    {
        ListNode *temp = new ListNode(carry);
        curr->next = temp;
    }

    return list;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *list1 = new ListNode(9);
    insertAtEnd(list1, 9);
    insertAtEnd(list1, 9);
    insertAtEnd(list1, 9);
    insertAtEnd(list1, 9);
    insertAtEnd(list1, 9);
    insertAtEnd(list1, 9);

    ListNode *list2 = new ListNode(9);
    insertAtEnd(list1, 9);
    insertAtEnd(list1, 9);
    insertAtEnd(list1, 9);

    display(addTwoNumbers(list1, list2));

    return 0;
}