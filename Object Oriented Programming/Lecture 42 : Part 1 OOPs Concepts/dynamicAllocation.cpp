/*
    DYNAMIC ALLOCATION IN CLASSES :


    NOTE : NAME OF POINTER POINTS TO FIRST PROPERTY OF THE CLASS;
*/

#include <iostream>
using namespace std;

class Hero
{
private:
    int health;
    char level;

public:
    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(int l)
    {
        level = l;
    }
};

int main()
{
    // static allocation
    Hero Paul;
    Paul.setHealth(55);
    Paul.setLevel('a');
    cout << "Health is : " << Paul.getHealth() << endl
         << "Level is : " << Paul.getLevel() << endl
         << endl;

    // dynamic allocation.
    Hero *Gon = new Hero;
    (*Gon).setHealth(55);
    (*Gon).setLevel('a');
    cout << "Health is : " << (*Gon).getHealth() << endl
         << "Level is : " << (*Gon).getLevel() << endl
         << endl;

    // better way :
    Gon->setHealth(65);
    Gon->setLevel('b');
    cout << "Health is : " << Gon->getHealth() << endl
         << "Level is : " << Gon->getLevel() << endl;

    return 0;
}
