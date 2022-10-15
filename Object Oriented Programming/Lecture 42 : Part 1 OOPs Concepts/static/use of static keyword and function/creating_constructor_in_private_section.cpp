/*
    CONSTRUCTOR CAN ALSO BE CREATED IN PRIVATE SECTION USING STATIC FUNCTIONS :
*/

#include <iostream>
using namespace std;

class Hero
{
private:
    // Creating Constructor in private section.
    Hero()
    {
        cout << "Constructor called." << endl;
    }

public:
    // because we can use static function without creating instance of class. we are using static functions.
    static Hero *createObject()
    {
        Hero *ptr = new Hero;
        // This will not destory because when we create object dynamically destructor will not call automatically. so this object lives until programe end. To destroy or call destructor we need to do it manually.
        return ptr;
    }

    void SomeFunction()
    {
        cout << "Some random function of class called." << endl;
    }
};

int main()
{
    // creating object dynamically.
    Hero *Paul = Hero::createObject();
    Paul->SomeFunction();
    return 0;
}
