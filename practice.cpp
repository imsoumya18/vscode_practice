#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node *&head, int data)
{
    Node *n = new Node(data);

    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL";
}

Node *revll(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

Node *revll_rec(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newhead = revll_rec(head->next);
    Node *headNext = head->next;
    headNext->next = head;
    head->next = NULL;

    return newhead;
}

int sumll(Node *head, int k)
{
    Node *fast = head, *slow = head;
    int sum = 0;

    for (int i = 1; i < k; i++)
        fast = fast->next;

    sum += fast->data;

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    sum += slow->data;

    return sum;
}

int mid(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *head = new Node(1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    // insertAtEnd(head, 7);

    display(head);
    cout << endl;
    // display(revll(head));
    // cout << endl;
    // display(revll_rec(head));

    cout << mid(head) << endl;

    return (0);
}