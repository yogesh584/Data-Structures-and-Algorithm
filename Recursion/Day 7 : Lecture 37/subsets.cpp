/*
    SUBSETS :
*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr)
{
    cout << "Printing the Array : ";
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void print2DVector(vector<vector<int>> vect)
{
    cout << "[ ";
    for (int i = 0; i < vect.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j];
        }
        cout << " ] ";
    }
    cout << "]" << endl;
}

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // printArray(output);
    // Base Case
    if (index > nums.size() - 1)
    {
        ans.push_back(output);
        return;
    }

    // Excluid Function Call
    solve(nums, output, index + 1, ans);

    // Include Function Call
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;

    vector<int> output;
    int index = 0;

    solve(nums, output, index, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    print2DVector(subsets(nums));

    return 0;
}
