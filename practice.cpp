// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> vct;

    for (int i = 1; i <= n; i++)
        if (i % 3 == 0)
            if (i % 5 == 0)
                vct.push_back("FizzBuzz");
            else
                vct.push_back("Fizz");
        else if (i % 5 == 0)
            vct.push_back("Buzz");
        else
            vct.push_back(to_string(i));

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 3;

    for (auto i : fizzBuzz(n))
        cout << i << endl;

    return 0;
}