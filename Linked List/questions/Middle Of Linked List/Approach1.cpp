/*
    MIDDLE OF A LINKED LIST
        APPROACH 1 :

*/

#include <iostream>
using namespace std;

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

void insertAtTail(Node *&Tail, int data)
{
    // Creting a new Node.
    Node *temp = new Node(data);
    Tail->next = temp;
    Tail = temp;
}

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

int getLength(Node *Head)
{

    int count = 0;

    while (Head != NULL)
    {
        Head = Head->next;
        count++;
    }

    return count;
}

Node *findMiddleNode(Node *Head, int length)
{
    int middle = ((length / 2) + 1);
    while (middle != 1)
    {
        Head = Head->next;
        middle--;
    }
    return Head;
}

int main()
{

    cout << endl
         << endl
         << endl;

    // creating Single Node.
    Node *node1 = new Node(10);
    Node *Head = node1;
    Node *Tail = node1;

    insertAtTail(Tail, 12);
    insertAtTail(Tail, 15);
    insertAtTail(Tail, 13);
    // insertAtTail(Tail, 14);

    printLinkedList(Head);

    int length = getLength(Head);

    Node *MiddleNode = findMiddleNode(Head, length);
    cout << "Middle Node is : " << MiddleNode->data << endl;

    return 0;
}
