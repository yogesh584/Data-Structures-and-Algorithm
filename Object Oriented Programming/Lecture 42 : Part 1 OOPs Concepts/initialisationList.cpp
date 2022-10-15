/*
    INITIALISATION LIST :
        WHAT : its nothing but a way to provide data to data members/properties in constructor.

    RESOURCES :
        CODEWITHHARRY : https://youtu.be/-Re7K7mHtv4

*/

#include <iostream>
using namespace std;

class Hero
{
    int a;
    int b;

public:
    // Hero(int i, int j) : a(i), b(j)
    // Hero(int i, int j) : a(i), b(i + j)
    // Hero(int i, int j) : a(i), b(2 * j)
    // Hero(int i, int j) : a(i), b(a + j)
    // Hero(int i, int j) : b(j), a(i + b) // Red Flag this will create problems because a will initialized first.
    Hero(int i, int j) : a(i), b(j)
    {
        cout << "Constructor is called " << endl;
        cout << "Value of a is : " << a << endl;
        cout << "Value of b is : " << b << endl;
    }
};

int main()
{
    Hero Paul(4, 6);

    return 0;
}
