/*
    CHECK PALINDROME IN LINKED LIST.
        APPROACH 1 :
            USING ANOTHER ARRAY (PUSHING LINKED LIST VALUES TO ARRAY AND THEN CHECKING)

*/

#include <iostream>
#include <vector>
using namespace std;

/*      CREATING A NODE     */
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int givenData)
    {
        this->data = givenData;
        this->next = NULL;
    }
};

/*      INSERTING AT TAIL       */
void insertAtTail(Node *&Tail, int data)
{
    // Creting a new Node.
    Node *temp = new Node(data);
    Tail->next = temp;
    Tail = temp;
}

/*      FUNCTION TO PRINT LINKED LIST       */
void printLinkedList(Node *&Head)
{
    Node *temp = Head;
    cout << "Printing Linked List : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

/*      FUNCTION TO CHECK PAILNDROME       */
bool checkPalindrom(Node *head)
{
    vector<int> arr;

    /*      TREAVERSING LINKED LIST     */
    while (head != NULL)
    {
        arr.push_back(head->data);
        head = head->next;
    }

    /*      USING TWO POINTERS APPROACH         */
    int index1 = 0;
    int index2 = arr.size() - 1;

    while (index1 <= index2)
    {
        if (arr[index1++] != arr[index2--])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << endl
         << endl
         << endl;
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    /*      INSERTING DATA TO LINKED LIST       */
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);

    /*      PRINTING LINKED LIST        */
    printLinkedList(head);
    cout << endl
         << endl;

    /*      CHECKING PAILNDROME     */
    if (checkPalindrom(head))
    {
        cout << "Palindrome " << endl;
    }
    else
    {
        cout << "Not Palindrome " << endl;
    }

    cout << endl
         << endl
         << endl;
    return 0;
}
