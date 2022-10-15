/*
    RECURSION DAY 2 :
        Reach Home Example
*/

#include <iostream>
using namespace std;

void reachHome(int src, int des)
{
    cout << "Source is : " << src << " and Destination is : " << des << endl;

    // Base Case :
    if (src == des)
    {
        return;
    }

    // pocessing
    // src++;

    // recursive call
    reachHome(++src, des);
}

int main()
{
    int src = 1;
    int des = 10;
    reachHome(src, des);
    return 0;
}
