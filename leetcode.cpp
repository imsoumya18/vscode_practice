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

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
	vector<ListNode *> vct(k, nullptr);

	ListNode *it = head;
	int cnt = 0;

	while (it != nullptr)
	{
		it = it->next;
		cnt++;
	}

	vector<int> cnt_list(k, cnt / k);

	int rem = cnt % k;

	for (int i = 0; i < rem; i++)
		cnt_list[i]++;

	it = head;

	for (int i = 0; i < k; i++)
	{
		if (it == nullptr)
			break;

		cnt = 0;

		vct[i] = it;

		while (cnt != cnt_list[i] - 1)
		{
			it = it->next;
			cnt++;
		}

		ListNode *prev = it;
		it = it->next;
		prev->next = nullptr;
	}

	return vct;
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
	// insertAtEnd(head, 4);
	// insertAtEnd(head, 5);
	// insertAtEnd(head, 6);
	// insertAtEnd(head, 7);
	// insertAtEnd(head, 8);
	// insertAtEnd(head, 9);
	// insertAtEnd(head, 10);

	display(head);

	int k = 5;

	for (auto i : splitListToParts(head, k))
		display(i);

	return 0;
}