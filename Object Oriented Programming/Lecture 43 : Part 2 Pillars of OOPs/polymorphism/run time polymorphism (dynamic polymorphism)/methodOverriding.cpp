/*
    METHOD OVERRIDING :
        RULES :
            1. THE METHOD OF THE PARENT CLASS AND THE METHOD OF THE CHILD CLASS MUST HAVE THE SAME NAME.
            2. THE METHOD OF THE PARENT CLASS AND THE METHOD OF THE CHILD CLASS MUST HAVE THE SAME PARAMETERS.
            3. IT IS POSSIBLE THROUGH INHERITANCE ONLY.
*/

#include <iostream>
using namespace std;

class Animal
{
public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog
{
public:
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    Dog d;
    d.speak();
    return 0;
}
