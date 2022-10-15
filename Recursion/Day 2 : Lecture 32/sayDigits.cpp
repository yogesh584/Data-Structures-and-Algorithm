/*
    SAY DIGITS :
    TIME COMPLIXITY : O(n)
*/
#include <iostream>
using namespace std;

void sayDigits(int number)
{
    // Base Case :
    if (number == 0)
    {
        return;
    }

    // processing :
    int lastDigit = number % 10;
    number = number / 10;
    string englishNumber[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Recurence Relation :
    sayDigits(number);

    cout << englishNumber[lastDigit] << " ";
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    sayDigits(n);

    cout << endl;
    return 0;
}
