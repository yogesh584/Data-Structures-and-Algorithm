/*
    STATIC FUNCTIONS :
        1. a method that same for all instance of class.

        2. static keyword ek asa method create karta h joo class koo belong karta h. Yani inko access karne kee liye aap koo object bana ne kee need nahi hoti.

        3. inke pass this keyword nahi hota ku kii this keyword pointer to current object hota h but yaha too object hee nahi h.

        4. static functions can only access static members.

*/

#include <iostream>
using namespace std;

class Hero
{
public:
    static int timeToComplete;

    static void random()
    {
        cout << timeToComplete << endl;
        cout << "Some Random Work" << endl;
    }
};

int Hero::timeToComplete = 5;

int main()
{
    Hero::random();
    return 0;
}
