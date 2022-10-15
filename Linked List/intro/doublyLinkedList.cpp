/*
    Doubly Linked List.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // constructor
    Node(int givenData)
    {
        this->prev = NULL;
        this->data = givenData;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory free for Node : " << value << endl;
    }
};

void insertAtHead(Node *&Head, Node *&Tail, int givenData)
{
    Node *newNode = new Node(givenData);
    if (Head == NULL)
    {
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }
}

void insertAtTail(Node *&Head, Node *&Tail, int givenData)
{
    Node *newNode = new Node(givenData);
    if (Tail == NULL)
    {
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        Tail->next = newNode;
        newNode->prev = Tail;
        Tail = newNode;
    }
}

void insertAtIndex(Node *&Head, Node *&Tail, int givenData, int positionToInsert)
{
    if (positionToInsert == 1)
    {
        insertAtHead(Head, Tail, givenData);
        return;
    }

    Node *temp = Head;
    for (int i = 1; i < (positionToInsert - 1); i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        insertAtTail(Head, Tail, givenData);
        return;
    }

    Node *newNode = new Node(givenData);

    newNode->prev = temp;
    newNode->next = temp->next;

    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtIndex(Node *&Head, Node *&Tail, int positionToDelete)
{
    if (positionToDelete == 1)
    {
        Node *temp = Head;
        Head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *current;
        Node *prev;

        int cnt = 1;
        while (cnt < positionToDelete)
        {
            prev = current;
            current = current->next;
            cnt++;
        }

        // Bhaiya ne yaha pe galti kar rakhi h. yaha par sahi code likha h.
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }

        if (current->next == NULL)
        {
            Tail = current->prev;
        }
        prev->next = current->next;
        current->prev = NULL;
        current->next = NULL;

        delete current;
    }
}

void printLinkedList(Node *Head)
{
    Node *iterator = Head;
    cout << "Printing Linked List : ";
    while (iterator != NULL)
    {
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
    cout << endl;
}

void printLinkedListUsingTail(Node *Tail)
{
    Node *iterator = Tail;
    cout << "Printing Linked List : ";
    while (iterator != NULL)
    {
        cout << iterator->data << " ";
        iterator = iterator->prev;
    }
    cout << endl;
}

int getLinkedListLength(Node *Head)
{
    int length = 0;
    Node *iterator = Head;
    while (iterator != NULL)
    {
        iterator = iterator->next;
        length++;
    }

    return length;
}

int main()
{
    Node *node1 = new Node(15);

    // Creating Head and Tail.
    Node *Head = node1;
    Node *Tail = node1;

    // todo : Inserting at Head.
    printLinkedList(Head);
    insertAtHead(Head, Tail, 25);
    printLinkedList(Head);

    // todo : Inserting at Tail.
    insertAtTail(Head, Tail, 67);
    printLinkedList(Head);

    // todo : Getting LinkList Length
    // cout << "Length of Linked List is : " << getLinkedListLength(Head) << endl;

    // todo : Inserting at index.
    insertAtIndex(Head, Tail, 56, 3);
    printLinkedList(Head);

    // todo : Deleting at Index.
    deleteAtIndex(Head, Tail, 4);
    printLinkedList(Head);
    printLinkedListUsingTail(Tail);

    return 0;
}
