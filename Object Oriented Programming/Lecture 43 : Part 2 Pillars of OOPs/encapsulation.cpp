/*
    ENCAPSULATION :
        WHAT : Wrapping up data members and functions.

        FULL ENCAPSULATED CLASS :
            WHAT : All Data Members are private.

        WAY TO DIFFRENCIATE BETWEEN ENCAPSULATION AND ABSTRACTION :
            ENCAPSULATION : DATA HIDING / INFORMATION HIDING
            ABSTRACTION : IMPLIMANTATION HIDING

        ADVANTAGE :
            1. If we want we can make class Read-Only.
            2. Code Resuablity.
            3. Unit Testing.
*/

#include <iostream>
using namespace std;

class Students
{
private:
    string name;
    int age;
    int height;

public:
    int getAge()
    {
        return this->age;
    }
};

int main()
{

    return 0;
}
