/*
    Function OverLoading.
*/
#include <iostream>
using namespace std;

class A
{
public:
    void sayHello()
    {
        cout << "Hello World" << endl;
    }
    void sayHello(string name)
    {
        cout << "Hello " << name << endl;
    }
};

int main()
{

    return 0;
}
