/*
    SINGLETON CLASS:
        WHAT : The singleton pattern is a design pattern that restricts the instantiation of a class to one object.
                                                        OR
                Singleton is a creational design pattern, which ensures that only one object of its kind exists and provides a single point of access to it for any other code.
*/
#include <iostream>
using namespace std;

class Hero
{
private:
    Hero()
    {
        cout << "constructor is called" << endl;
    }

public:
    static int count;
    static Hero *createObject()
    {
        if (count == 0)
        {
            Hero *ptr = new Hero;
            count++;
            return ptr;
        }
        else
        {
            return NULL;
        }
    }

    void doSomething()
    {
        cout << "I am doing something" << endl;
    }
};

int Hero::count = 0;

int main()
{
    // Creating First instance.
    Hero *myhero = Hero::createObject();
    if (myhero != NULL)
    {
        myhero->doSomething();
    }
    else
    {
        cout << "only one instance is allowed." << endl;
    }

    // Trying to create more instance (not possible)
    Hero *myhero2 = Hero::createObject();
    if (myhero2 != NULL)
    {
        myhero2->doSomething();
    }
    else
    {
        cout << "only one instance is allowed." << endl;
    }

    return 0;
}
