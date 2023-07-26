// @author Soumya
#include <iostream>
#include <vector>
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

bool isPalindrome(ListNode *head)
{
    int flag = 0;
    vector<int> vct;
    ListNode *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    display(slow);

    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ListNode *head = new ListNode(1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    display(head);
    cout << endl;

    cout << isPalindrome(head) << endl;

    return 0;
}