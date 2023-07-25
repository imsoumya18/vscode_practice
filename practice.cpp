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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *ans = nullptr, *it = nullptr;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val < list2->val)
        {
            insertAtEnd(ans, list1->val);
            list1 = list1->next;
        }
        else
        {
            insertAtEnd(ans, list2->val);
            list2 = list2->next;
        }
    }

    while (list1 != nullptr)
    {
        insertAtEnd(ans, list1->val);
        list1 = list1->next;
    }

    while (list2 != nullptr)
    {
        insertAtEnd(ans, list2->val);
        list2 = list2->next;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *head = new ListNode(1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 5);
    insertAtEnd(head, 7);

    ListNode *head2 = new ListNode(5);
    insertAtEnd(head2, 6);
    insertAtEnd(head2, 8);

    display(head);
    cout << endl;
    ListNode *n = mergeTwoLists(head, head2);
    display(n);
    cout << endl;

    return 0;
}