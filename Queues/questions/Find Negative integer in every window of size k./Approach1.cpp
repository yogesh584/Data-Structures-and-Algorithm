#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;

    // process first window of k size;
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // store answer of first k sized window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process remaning windows
    for (int i = K; i < N; i++)
    {

        // remove Element from deque
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }

        // add Element from deque
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    cout << endl
         << endl
         << endl;

    long long int arr[] = {-8, 2, 3, -6, 10};
    int n = 5; // size of array
    int k = 2; // size of window
    vector<long long int> ans = printFirstNegativeInteger(arr, n, k);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << endl
         << endl
         << endl;
    return 0;
}

/*
    SAMPLE INPUTS :
        N = 8
        A[] = {12, -1, -7, 8, -15, 30, 16, 28}
        K = 3

        ANSWER : -1 -1 -7 -15 -15 0
*/