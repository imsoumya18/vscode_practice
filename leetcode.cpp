// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int com;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> tops{2, 1, 2, 4, 2, 2}, bottoms{5, 2, 6, 2, 3, 2};

    cout << minDominoRotations(tops, bottoms) << endl;

    return 0;
}