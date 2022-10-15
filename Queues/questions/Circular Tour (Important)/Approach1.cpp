/*
    CIRCULAR TOUR (IMPORTANT ONLINE ASSESMENT)
*/
#include <iostream>
#include <queue>
using namespace std;

class petrolPump
{
public:
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;

        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}
int main()
{
    cout << endl
         << endl
         << endl;

    /*      CREATING PETROL PUMP        */
    petrolPump p[4];

    /* ASSINGNING TEMP VALUES TO IT      */
    p[0].petrol = 4;
    p[0].distance = 6;

    p[1].petrol = 6;
    p[1].distance = 5;

    p[2].petrol = 7;
    p[2].distance = 3;

    p[3].petrol = 4;
    p[3].distance = 5;

    int startingPoint = tour(p, 4);
    cout << "Starting Point of Petrol Pump is : " << startingPoint << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
