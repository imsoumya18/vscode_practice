// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// -> print the topmost element of maxheap
// -> pop the topmost element
// -> heapify
// -> repeat

// heapify
void heapify(vector<int> &harr, int i)
{
    int largest = i;
    int l = 2 * i, r = 2 * i + 1;

    if (l <= harr.size() && harr[l] > harr[largest])
        largest = l;

    if (r <= harr.size() && harr[r] > harr[largest])
        largest = r;

    if (largest != i)
    {
        swap(harr[i], harr[largest]);
        heapify(harr, largest);
    }
}

// heap sort
void heapSort(vector<int> &harr)
{
    for (int i = harr.size() / 2 - 1; i >= 0; i--)
        heapify(harr, i);

    for (int i = harr.size() - 1; i > 0; i--)
    {
        swap(harr[0], harr[i]);
        heapify(harr, 0);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> harr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (auto i : harr)
        cout << i << " ";

    cout << endl;

    heapSort(harr);

    for (auto i : harr)
        cout << i << " ";

    return 0;
}