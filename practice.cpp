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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *curr = head, *prev = new ListNode(-1);
    prev->next = curr;
    set<int> s;

    while (curr != nullptr)
    {
        if (s.find(curr->val) == s.end())
        {
            s.insert(curr->val);
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if (curr == head)
                head = curr->next;
            curr = curr->next;
            prev->next = curr;
        }
    }

    return head;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *head = new ListNode(2);
    insertAtEnd(head, 9);
    insertAtEnd(head, 2);
    insertAtEnd(head, 6);
    insertAtEnd(head, 8);
    insertAtEnd(head, 9);
    insertAtEnd(head, 10);
    insertAtEnd(head, 9);
    insertAtEnd(head, 10);

    display(head);
    cout << endl;
    ListNode *n = deleteDuplicates(head);
    display(n);

    return 0;
}