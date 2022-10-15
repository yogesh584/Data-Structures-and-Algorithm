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

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

/*      SORTING LINKED LIST     */
Node *sort0s1sand2s(Node *&head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            insertAtTail(zeroTail, temp);
        }
        else if (temp->data == 1)
        {
            insertAtTail(oneTail, temp);
        }
        else if (temp->data == 2)
        {
            insertAtTail(twoTail, temp);
        }

        temp = temp->next;
    }

    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }

    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
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
    head = sort0s1sand2s(head);
    printLinkedList(head);
    return 0;
}
