/*
    MULTILEVEL INHERITANCE :
*/

#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
    int weight;

    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
};

class GermanShepherd : public Dog
{
};

int main()
{
    GermanShepherd d;
    d.speak();
    return 0;
}
