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
    if (list1 == nullptr)
        return list2;

    if (list2 == nullptr)
        return list1;

    ListNode *ans = nullptr, *it1 = nullptr, *it2 = nullptr;

    if (list1->val <= list2->val)
    {
        ans = list1;
        it1 = list1;
        it2 = list2;
    }
    else
    {
        ans = list2;
        it1 = list2;
        it2 = list1;
    }

    while (it2 != nullptr)
    {
        if (it1->next == nullptr)
        {
            it1->next = it2;
            break;
        }

        if (it1->next->val >= it2->val)
        {
            ListNode *temp = it2;
            it2 = it2->next;
            ListNode *temp2 = it1->next;
            it1->next = temp;
            temp->next = temp2;
            it1 = it1->next;
        }
        else
            it1 = it1->next;
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
    // insertAtEnd(head, 3);
    // insertAtEnd(head, 5);

    ListNode *head2 = new ListNode(2);
    // insertAtEnd(head2, 4);
    // insertAtEnd(head2, 5);

    display(head);
    cout << endl;

    display(head2);
    cout << endl;

    ListNode *n = mergeTwoLists(head, head2);
    display(n);
    cout << endl;

    return 0;
}