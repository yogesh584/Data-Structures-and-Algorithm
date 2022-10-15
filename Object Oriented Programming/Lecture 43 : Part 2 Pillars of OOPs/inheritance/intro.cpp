/*
    INHERITANCE :

*/

#include <iostream>
using namespace std;

class Human
{
public:
    int height = 5;
    int weight = 60;
    int age = 28;

    int getAge()
    {
        return this->age;
    }
};

class Male : public Human
{
public:
    string color = "yellow";
    void sleep()
    {
        cout << "Male is Sleeping" << endl;
    }
};

int main()
{
    Male Love;
    cout << Love.color << endl;
    cout << Love.age << endl;
    Love.sleep();
    return 0;
}
