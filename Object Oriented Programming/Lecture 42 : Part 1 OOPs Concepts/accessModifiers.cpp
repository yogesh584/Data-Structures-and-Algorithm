/*
    ACCESS MODIFIERS :
        Access Modifiers or Access Specifiers in a class are used to assign the accessibility to the class members, i.e., they set some restrictions on the class members so that they can’t be directly accessed by the outside functions.
        There are 3 types of access modifiers available in C++:
            1. Public
            2. Private  (Default)
            3. Protected
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
    Hero ramesh;
    // ramesh.health = 70;
    // ramesh.level = 'a';

    // cout << "Health is : " << ramesh.health << endl << "Level is : " << ramesh.level << endl;

    ramesh.setHealth(50);
    ramesh.setLevel('a');

    cout << "Health is : " << ramesh.getHealth() << endl
         << "Level is : " << ramesh.getLevel() << endl;

    return 0;
}
