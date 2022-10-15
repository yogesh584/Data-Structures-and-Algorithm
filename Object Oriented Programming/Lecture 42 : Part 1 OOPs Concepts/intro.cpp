/*
    imp -> important
    OBJECT ORIENTED PROGRAMMING :

    What is Object :
        1. Object is an Entity who has some state/properties and behaviour/methods.
        2. Object is instance of class.

    What is Class :
        1. class is a user defined data types.
        2. class is like a template.
    Empty Class :
        1. class without any properties and methods.
imp     2. size of empty class is 1 byte to identify the object or track rakne kee liye.


*/

#include <iostream>
using namespace std;
// creating a class.
class Hero
{
public:
    // properties.
    int something;
    char name[100]; // 100 bytes
    int health;     // 4 bytes
    char level;     // 1 byte
};

class EmptyClass // Empty Class
{
};

int main()
{
    // creating a object.
    Hero Paul;
    cout << "size of Paul : " << sizeof(Paul) << endl; // 108 bytes

    EmptyClass e;
    cout << "size of e : " << sizeof(e) << endl;
    return 0;
}
