// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

void heap_insert(vector<int> &heap, int p) {}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> heap{50, 30, 40, 10, 5, 20, 30};
    int p = 60;

    heap_insert(heap, p);

    return 0;
}