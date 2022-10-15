/*
    MULTIPLE INHERITANCE :
*/

#include <iostream>
using namespace std;

class A
{
public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class B
{
public:
    void bark()
    {
        cout << "Bark" << endl;
    }
};

class C : public A, public B
{
};

int main()
{
    C c;
    c.speak();
    c.bark();
    return 0;
}
