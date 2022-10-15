/*
    Refrence Links to Study :
    1. College Wala Bhaiya Youtube Channel : https://youtu.be/f0KlB8yaC8Q
    2. GFG : https://www.geeksforgeeks.org/data-structure-alignment-how-data-is-arranged-and-accessed-in-computer-memory/
*/

#include <iostream>
using namespace std;

class Hero
{
    char a;   // 1 byte -> 7 bytes padding.
    double b; // 8 bytes
};

int main()
{
    Hero Paul;
    cout << "Size is : " << sizeof(Paul) << endl; // Output : 16 bytes because max size data type is double (8 bytes) so char takes 7 bytes of padding.

    return 0;
}
