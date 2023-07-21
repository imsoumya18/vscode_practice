// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

class Hero
{
private:
    int point;

public:
    int life;

    Hero()
    {
        cout << "no parameter constructor" << endl;
    }

    Hero(int x)
    {
        cout << "parameterised constructor: " << x << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Hero h1(4);

    return 0;
}