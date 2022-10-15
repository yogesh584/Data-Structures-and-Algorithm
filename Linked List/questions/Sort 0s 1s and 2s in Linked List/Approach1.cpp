/*
    SORT 0S 1S AND 2S IN LINKED LIST
    APPROACH 1 :
        COUNT 0S 1S AND 2S AND INSERT.
*/
#include <iostream>
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

/*      COUNT 0S 1S AND 2S      */
void count0s1sAnd2s(Node *head, int &total0s, int &total1s, int &total2s)
{
    while (head != NULL)
    {
        if (head->data == 0)
        {
            total0s++;
        }
        else if (head->data == 1)
        {
            total1s++;
        }
        else if (head->data == 2)
        {
            total2s++;
        }
        head = head->next;
    }
}

/*      SORTING LINKED LIST     */
void sort0s1sand2s(Node *head)
{
    int total0s = 0, total1s = 0, total2s = 0;
    count0s1sAnd2s(head, total0s, total1s, total2s);

    while (head != NULL)
    {
        if (total0s > 0)
        {
            head->data = 0;
            total0s--;
        }
        else if (total1s > 0)
        {
            head->data = 1;
            total1s--;
        }
        else if (total2s > 0)
        {
            head->data = 2;
            total2s--;
        }
        head = head->next;
    }
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    /*      INSERTING DATA TO LINKED LIST       */
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);

    /*      PRINTING AND SORTING 0S 1S AND 2S      */
    printLinkedList(head);
    sort0s1sand2s(head);
    printLinkedList(head);

    return 0;
}
