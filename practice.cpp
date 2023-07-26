// @author Soumya
#include <iostream>
#include <stack>
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

ListNode *reverseLL(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *prev = nullptr, *curr = head, *nxt;

    while (curr != nullptr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

ListNode *addTwoNumbers(ListNode *l1)
{
    l1 = reverseLL(l1);
    ListNode *it = l1;
    int sum = 0, carry = 1;

    while (carry != 0)
    {
        sum = l1->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        l1->val = sum;

        if (l1->next == nullptr)
        {
            l1->next = new ListNode(carry);
            carry = 0;
        }
        else
            l1 = l1->next;
    }

    return reverseLL(it);

    // l1 = reverseLL(l1);
    // int sum = l1->val + 1, carry = 0;
    // carry = sum / 10;
    // sum = sum % 10;
    // l1->val = sum;

    // if (carry != 0)
    //     if (l1->next == nullptr)
    //         l1->next = new ListNode(carry);
    //     else
    //         l1->next->val += carry;

    // return reverseLL(l1);

    // ListNode *ans = nullptr;

    // while (l1 || l2)
    // {
    //     int sum = 0;

    //     if (l1 != nullptr)
    //     {
    //         sum += l1->val;
    //         l1 = l1->next;
    //     }

    //     if (l2 != nullptr)
    //     {
    //         sum += l2->val;
    //         l2 = l2->next;
    //     }

    //     sum += carry;
    //     carry = sum / 10;
    //     sum = sum % 10;

    //     insertAtEnd(ans, sum);
    // }

    // if (carry != 0)
    //     insertAtEnd(ans, carry);

    // return reverseLL(ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *head = new ListNode(4);
    insertAtEnd(head, 9);
    // insertAtEnd(head, 6);
    // insertAtEnd(head, 9);

    ListNode *head2 = new ListNode(5);
    insertAtEnd(head2, 6);
    insertAtEnd(head2, 4);

    display(head);
    cout << endl;
    // display(head2);
    cout << endl;
    ListNode *n = addTwoNumbers(head);
    display(n);

    return 0;
}