#include <iostream>
#include <string>
using namespace std;

class student
{
    int roll;
    char name[];

    int add(int x, int y)
    {
        return x + y;
    }
};

int main()
{
    student *s1 = new student();

    cout << s1.add(4, 3) << endl;

    return (0);
}