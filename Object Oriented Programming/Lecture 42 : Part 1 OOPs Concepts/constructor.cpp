/*
    CONSTRUCTOR :
        A method that call automatically when an instance of class created.

        PROPERTIES :
            1. Same name as class name.
            2. call automatically when instance of class created.
            4. Constructor will call no matter you call statically or dynamically.
            5. Don't have any return type.

        TYPES OF CONSTRUCTOR :
            1. DEFAULT CONSTRUCTOR
            2. PARAMETERAISED CONSTRUCTOR
            3. COPY CONSTROCTOR


        1. DEFAULT CONSTRUCTOR :
            a constructor that don't take any parameter and do some work.

            PROPERTIES :
                1. Already Defined by default.

        2. PARAMETERAISED CONSTRUCTOR :
            a constructor that take any parameter and do some work.

        3. COPY CONSTROCTOR :
            a constructor that take an object and copy one object to another.

            PROPERTIES :
                1. Already Defined by default.
    THIS :
        1. this is a pointer to the current object.
        2. address of this and address of object is same.
*/

#include <iostream>
using namespace std;

class Test1
{
public:
    // constructor.
    Test1()
    {
        cout << "Constructor is called." << endl;
    }
};

class Test2
{
private:
    int health;

public:
    // Parametrised Constructor
    Test2(int health)
    {
        // cout << "this : " << this << endl;
        this->health = health;
    }

    // Copy constructor
    Test2(Test2 &temp)
    {
        cout << "copy constructor called" << endl;
        this->health = temp.health;
    }

    int getHealth()
    {
        return health;
    }
};

int main()
{
    /*
    cout << "Before Object creation " << endl;
    Test1 t1;
    cout << "After Object creation " << endl;
    */

    /*
    Test2 t2(55);
    cout << "Address of t2 is : " << &t2 << endl;
    cout << "Health : " << t2.getHealth() << endl;
    */

    Test2 t2(34);
    Test2 newt2(t2);

    cout << newt2.getHealth() << endl;

    return 0;
}
