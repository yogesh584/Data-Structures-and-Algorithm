#include <iostream>
using namespace std;

class A
{
public:
    void func()
    {
        cout << "Function of A" << endl;
    }
};

class B
{
public:
    void func()
    {
        cout << "Function of B" << endl;
    }
};

class C : public A, public B
{
};

int main()
{
    C obj;
    // obj.func(); // func is ambiguous
    obj.A::func();
    return 0;
}
