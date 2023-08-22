// @author Soumya
#include <iostream>
using namespace std;

// linked list implementation
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *bottom;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
        bottom = nullptr;
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

void display2(ListNode *&head)
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << "-->";
        temp = temp->bottom;
    }

    cout << "NULL" << endl;
}

ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;

    if (l2 == nullptr)
        return l1;

    ListNode *ans = new ListNode(-1), *temp = ans;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            temp->bottom = l1;
            temp = l1;
            l1 = l1->bottom;
        }
        else
        {
            temp->bottom = l2;
            temp = l2;
            l2 = l2->bottom;
        }
    }

    while (l1 != nullptr)
    {
        temp->bottom = l1;
        temp = l1;
        l1 = l1->bottom;
    }

    while (l2 != nullptr)
    {
        temp->bottom = l2;
        temp = l2;
        l2 = l2->bottom;
    }

    return ans->bottom;
}

ListNode *flatten(ListNode *root)
{
    if (root->next == nullptr)
        return root;

    ListNode *right = flatten(root->next);
    root->next = nullptr;

    ListNode *ans = merge(root, right);

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *head = new ListNode(5);
    insertAtEnd(head, 10);
    insertAtEnd(head, 19);
    insertAtEnd(head, 28);

    head->bottom = new ListNode(7);
    head->bottom->bottom = new ListNode(8);
    head->bottom->bottom->bottom = new ListNode(30);

    head->next->bottom = new ListNode(20);

    head->next->next->bottom = new ListNode(22);
    head->next->next->bottom->bottom = new ListNode(50);

    head->next->next->next->bottom = new ListNode(35);
    head->next->next->next->bottom->bottom = new ListNode(40);
    head->next->next->next->bottom->bottom->bottom = new ListNode(45);

    display(head);
    cout << endl
         << endl;

    display2(head);
    display2(head->next);
    display2(head->next->next);
    display2(head->next->next->next);
    cout << endl
         << endl;

    ListNode *ans = flatten(head);

    display2(ans);

    return 0;
}