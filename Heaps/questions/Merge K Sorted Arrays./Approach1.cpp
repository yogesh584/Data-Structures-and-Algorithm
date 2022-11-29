#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    int i;
    int j;

    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return (a->data > b->data);
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    // step 1 : sarre arrays k first element insert karo.
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    // step 2 : find minimum element and uss arrays ka next elem daal do.
    vector<int> ans;
    while (minHeap.size() > 0)
    {
        node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if (j + 1 < kArrays[i].size())
        {
            node *next = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main()
{
    cout << endl
         << endl
         << endl;

    vector<vector<int>> arrays = {{3, 5, 7}, {1, 2, 4, 8}, {6, 9}};
    vector<int> mergedArrray = mergeKSortedArrays(arrays, 3);

    cout << "Merged List is : ";
    for (int i = 0; i < mergedArrray.size(); i++)
    {
        cout << mergedArrray[i] << " ";
    }

    cout << endl
         << endl
         << endl;

    return 0;
}
