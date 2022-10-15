/*
    COPY ASSINGMENNT OPERATOR :
        to copy one object to another.

    DESTRUCTOR :
        to memory dellocate of an instance.

        PROPERTIES :
            1. name same as class name.
            2. No Return type.
            3. No Input Parameter.
            4. Diffrence between constructor is '~' means distructor name sarts with '~'.
            5. Already have a default distructor in every class.
            6. Joo bhi object aap static allocation ke through karvate h unke liye destructor automatically call hota h.but dynamically allocation ke case me manually call karna hoga. using delete keyword.
*/

#include <iostream>
using namespace std;

class Hero
{
private:
    int health;
    char level;

public:
    Hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }

    ~Hero()
    {
        cout << "Destructor is called" << endl;
    }

    void printHero()
    {
        cout << "Health is : " << this->health << endl
             << "Level is : " << this->level << endl
             << endl;
    }
};

int main()
{
    Hero Paul(45, 'a');
    Hero Gon(67, 'b');

    Hero *Hitachi = new Hero(89, 'c');

    // Printing Heroes before copy assingment operator.
    Paul.printHero();
    Gon.printHero();

    // copy assingnment Operator.
    Paul = Gon;

    // Printing Heroes after copy assingment operator.
    Paul.printHero();
    Gon.printHero();

    // Manually Calling Destructor For Hitachi.
    delete Hitachi;

    return 0;
}
