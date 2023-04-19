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

void insertatend(Node *&head, int val)
{
    Node *n = new Node(val);

    if (head == NULL)
        return;

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

Node *reverseLL_iter(Node *&head)
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

Node *reverseLL_recur(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newhead = reverseLL_recur(head->next);
    Node *headnext = head->next;
    headnext->next = head;
    head->next = NULL;

    return newhead;
}

int midofLL(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}

int sum_both_nth(Node *head, int k)
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

void rmv_duplicates(Node *&head)
{
    Node *temp = head;

    while (temp->next)
    {
        if (temp->data == temp->next->data)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
}

Node *swap_in_pairs(Node *&head)
{
    Node *dummy = new Node(-1), *prev = dummy, *curr = head;
    dummy->next = head;

    while (curr && curr->next)
    {
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next = curr;
        curr = curr->next;
        prev = prev->next->next;
    }

    return dummy->next;
}

void del_mid_node(Node *&head)
{
    Node *fast = head, *slow = new Node(-1);
    slow->next = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
}

void rmv_nth_end(Node *&head, int k)
{
    Node *fast = head, *slow = new Node(-1);
    slow->next = head;

    for (int i = 1; i < k; i++)
        fast = fast->next;

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *head = new Node(1);

    insertatend(head, 2);
    insertatend(head, 3);
    insertatend(head, 4);
    insertatend(head, 5);
    insertatend(head, 6);
    insertatend(head, 7);
    insertatend(head, 8);

    display(head);
    // display(reverseLL_iter(head));
    // display(reverseLL_recur(head));
    // cout << midofLL(head) << endl;
    // cout << sum_both_nth(head, 2) << endl;
    // rmv_duplicates(head);
    // display(head);
    // display(swap_in_pairs(head));
    // del_mid_node(head);
    // display(head);
    rmv_nth_end(head, 3);
    display(head);

    return 0;
}
