// @author Soumya
#include <iostream>
using namespace std;

// linked list implementation
class node
{
public:
    int val;
    node *next;

    node(int x)
    {
        val = x;
        next = nullptr;
    }
};

// insert node at head
void insertAtHead(node *&head, int val)
{
    node *temp = head;

    head = new node(val);
    head->next = temp;
}

// insert node at end
void insertAtEnd(node *&head, int val)
{
    node *n = new node(val);

    if (head == nullptr)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = n;
}

// print elements of linked list
void display(node *&head)
{
    node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << "-->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    node *head = new node(2);
    insertAtEnd(head, 4);
    insertAtEnd(head, 6);
    insertAtEnd(head, 8);
    insertAtHead(head, 10);
    insertAtHead(head, 12);

    display(head);

    return 0;
}