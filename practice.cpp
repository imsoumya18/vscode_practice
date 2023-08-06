// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{1, 2, 3, 4, 5};

    for (auto i : vector<int>(vct.begin(), vct.end() - 2))
        cout << i << " ";
    cout << endl;

    return 0;
}