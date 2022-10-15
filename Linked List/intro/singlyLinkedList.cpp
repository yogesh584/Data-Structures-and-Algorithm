/*
    SINGLY LINKED LIST :
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

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
        cout << "memory free for Node : " << value << endl;
    }
};

void insertAtHead(Node *&Head, int data)
{
    // Creting a new Node.
    Node *temp = new Node(data);
    temp->next = Head;
    Head = temp;
}

void insertAtTail(Node *&Tail, int data)
{
    // Creting a new Node.
    Node *temp = new Node(data);
    Tail->next = temp;
    Tail = temp;
}

void insertAtIndex(Node *&Head, Node *&Tail, int data, int index)
{
    // Checking Base Cases
    if (index == 1)
    {
        insertAtHead(Head, data);
        return;
    }

    // Creating a Iterator Node.
    Node *iterator = Head;

    // Creting a new Node.
    Node *temp = new Node(data);

    for (int i = 1; i < index - 1; i++)
    {
        iterator = iterator->next;
    }

    if (iterator->next == NULL)
    {
        insertAtTail(Tail, data);
        return;
    }

    temp->next = iterator->next;
    iterator->next = temp;
}

void deleteAtIndex(Node *&Head, Node *&Tail, int positionToDelete)
{
    // Deleting First/Start Node.
    if (positionToDelete == 1)
    {
        Node *temp = Head;
        Head = Head->next;
        temp->next = NULL;
        delete temp;
    }
    // Deleting Middle or Last/Tail Node.
    else
    {
        Node *currentIterator = Head;
        Node *previousIterator = NULL;

        // Iteratring Linked List.
        for (int i = 1; i < positionToDelete; i++)
        {
            previousIterator = currentIterator;
            currentIterator = currentIterator->next;
        }

        previousIterator->next = currentIterator->next;

        // Shifting Tail to Backwards if Deleting From Last.
        if (currentIterator->next == NULL)
        {
            Tail = previousIterator;
        }
        currentIterator->next = NULL;

        delete currentIterator;
    }
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

int main()
{
    cout << endl
         << endl
         << endl;

    // creating Single Node.
    Node *node1 = new Node(10);

    // todo : Printing Node1 Data.
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // todo : Creating Head and Tail.
    Node *Head = node1;
    Node *Tail = node1;

    // todo: Inserting Nodes at Starting (Head).
    // printLinkedList(Head);
    // insertAtHead(Head, 12);
    // printLinkedList(Head);
    // insertAtHead(Head, 15);
    // printLinkedList(Head);

    // todo : Inserting Nodes at Ending (Tail).
    printLinkedList(Head);
    insertAtTail(Tail, 12);
    printLinkedList(Head);
    insertAtTail(Tail, 15);
    printLinkedList(Head);

    // todo : Insert Nodes at given Index.
    insertAtIndex(Head, Tail, 55, 1);
    printLinkedList(Head);
    insertAtIndex(Head, Tail, 34, 5);
    printLinkedList(Head);

    // todo : Deleting Nodes at Given Index.
    deleteAtIndex(Head, Tail, 1);

    // todo : Printing Head and Tail.
    cout << "Head is : " << Head->data << endl;
    cout << "Tail is : " << Tail->data << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
