#include <iostream>
using namespace std;
// TC : O(n)
void counting(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    counting(n - 1); // Recurisnce Relation
}
int main()
{
    int n;
    cin >> n;
    counting(n);
    cout << endl;
    return 0;
}
