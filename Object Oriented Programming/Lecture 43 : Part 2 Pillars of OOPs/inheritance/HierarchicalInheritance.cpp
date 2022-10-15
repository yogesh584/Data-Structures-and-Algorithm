/*
    HIERACHICAL INHERITANCE
*/

#include <iostream>
using namespace std;
class A
{
public:
    void func1()
    {
        cout << "inside function 1" << endl;
    }
};

class B : public A
{
public:
    void func2()
    {
        cout << "inside fuction 2" << endl;
    }
};

class C : public A
{
public:
    void func3()
    {
        cout << "inside functin 3" << endl;
    }
};

int main()
{
    B obj1;
    obj1.func1();
    obj1.func2();

    C obj2;
    obj2.func1();
    obj2.func3();

    return 0;
}
