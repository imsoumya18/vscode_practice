// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
#include <set>
using namespace std;

void print(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

vector<int> getDivisors(int n)
{
    // code here
    vector<int> vct;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            vct.push_back(i);

            if (i * i != n)
                vct.push_back(n / i);
        }

    sort(vct.begin(), vct.end());

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    print(primeFactors(13));

    return 0;
}