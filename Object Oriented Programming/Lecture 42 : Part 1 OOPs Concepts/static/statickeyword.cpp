/*
    STATIC KEYWORD :
        1. a property that same for all instance of class.
            Example : time to compleate in tekken game. time to complete is dependent to Hero class.
        2. static keyword ek asa data member/property create karta h joo class koo belong karta h. Yani inko access karne kee liye aap koo object bana ne kee need nahi hoti.
*/

#include <iostream>
using namespace std;

class Hero
{
public:
    static int timeToComplete;
};

int Hero::timeToComplete = 5;

int main()
{

    // Accessing static property without creating instance/object.
    cout << Hero::timeToComplete << endl;
    return 0;
}
