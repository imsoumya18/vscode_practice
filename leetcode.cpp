// @author Soumya
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void print1d(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";

    cout << endl;
}

void print2d(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

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

void insertAtEnd(node *&head, int x)
{
    if (head == nullptr)
    {
        head = new node(x);
        return;
    }

    node *curr = head;

    while (curr->next)
        curr = curr->next;

    curr->next = new node(x);
}

void printList(node *head)
{
    node *curr = head;

    while (curr)
    {
        cout << curr->val << "-->";
        curr = curr->next;
    }

    cout << "NULL" << endl;
}

int cnt = 0;

void merge(vector<int> &vct, int l, int mid, int r)
{
    vector<int> temp;
    int left = l, right = mid + 1;

    while (left <= mid && right <= r)
        if (vct[left] <= vct[right])
            temp.push_back(vct[left++]);
        else
        {
            cnt += (mid - left + 1);
            temp.push_back(vct[right++]);
        }
    while (left <= mid)
        temp.push_back(vct[left++]);

    while (right <= r)
        temp.push_back(vct[right++]);

    for (int i = l; i <= r; i++)
        vct[i] = temp[i - l];
}

void mergeSort(vector<int> &vct, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(vct, l, mid);
        mergeSort(vct, mid + 1, r);

        merge(vct, l, mid, r);
    }
}

int inversionCount(vector<int> &arr)
{
    // Code Here
    mergeSort(arr, 0, arr.size() - 1);

    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr{2, 3, 4, 5, 6};

    cout << inversionCount(arr) << endl;

    return 0;
}
