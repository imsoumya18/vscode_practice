// @author Soumya
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

void addNode(Node *&head, int val)
{
    Node *n = new Node(val);

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
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }

    cout << "NULL" << endl;
}

Node *revLL_iter(Node *&head)
{
    Node *prev = NULL, *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

Node *revLL_recur(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = revLL_recur(head->next);
    Node *headNext = head->next;
    headNext->next = head;
    head->next = NULL;

    return newHead;
}

void midLL(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    cout << slow->data << endl;
}

void del_mid(Node *&head)
{
    Node *fast = head, *dummy = new Node(-1), *slow = dummy;
    dummy->next = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
}

void kth_end(Node *head, int k)
{
    Node *fast = head, *slow = head;

    for (int i = 1; i < k; i++)
        fast = fast->next;

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    cout << slow->data << endl;
}

void remove_kth_end(Node *&head, int k)
{
    Node *fast = head, *dummy = new Node(-1), *slow = dummy;
    dummy->next = head;

    for (int i = 1; i < k; i++)
        fast = fast->next;

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
}

void remove_duplicates(Node *&head)
{
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
}

Node *swap_in_pairs(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head, *t = head->next, *prev;

    while (curr && curr->next)
    {
        Node *temp = curr->next;
        curr->next = temp->next;
        temp->next = curr;
        if (curr != head)
            prev->next = temp;
        prev = curr;
        curr = curr->next;
    }

    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *head = new Node(1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);
    addNode(head, 6);

    display(head);

    // display(revLL_iter(head));

    // display(revLL_recur(head));

    // midLL(head);

    // del_mid(head);
    // display(head);

    // kth_end(head, 5);

    // remove_kth_end(head, 5);
    // display(head);

    // remove_duplicates(head);
    // display(head);

    // swap_in_pairs(head);
    // display(head);

    // display(swap_in_pairs(head));

    return 0;
}