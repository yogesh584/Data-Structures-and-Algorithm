/*
    REVERSE A LINKED LIST :
        APPROACH 1 :
            USING THREE POINTER APPROACH
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
    Node *Head = node1;
    Node *Tail = node1;

    insertAtTail(Tail, 12);
    insertAtTail(Tail, 15);
    insertAtTail(Tail, 13);
    insertAtTail(Tail, 14);

    printLinkedList(Head);

    Node *prev = NULL;
    Node *curr = Head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    Head = prev;

    printLinkedList(Head);

    return 0;
}
