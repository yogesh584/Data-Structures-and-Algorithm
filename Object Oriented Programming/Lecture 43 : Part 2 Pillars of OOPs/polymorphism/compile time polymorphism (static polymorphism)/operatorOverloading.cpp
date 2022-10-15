/*
    OPERATOR OVERLOADING :
*/

#include <iostream>
using namespace std;

class A
{
public:
    int a;
    int b;

    void operator+(A &obj)
    {
        cout << "output : " << this->a - obj.a << endl
             << endl;
    }

    void operator()()
    {
        cout << "mai bracket hu" << endl;
    }
};

int main()
{
    cout << endl;
    A obj;
    A obj2;
    obj.a = 8;
    obj2.a = 6;
    obj + obj2;

    obj();

    return 0;
}
