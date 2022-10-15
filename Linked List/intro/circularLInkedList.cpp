/*
    CIRCULAR LINKED LIST
        1. SINGLY CIRCULAR LINKED LIST
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int givenData)
    {
        this->data = givenData;
        this->next = NULL;
    }
};

void insertElement(Node *&Tail, int givenData, int element = 0)
{
    Node *temp = new Node(givenData);
    if (Tail == NULL)
    {
        Tail = temp;
        temp->next = temp;
        return;
    }

    Node *curr = Tail;

    // Assuming that element exist in Linkedlist.
    while (curr->data != element)
    {
        curr = curr->next;
    }

    // element found !
    temp->next = curr->next;
    curr->next = temp;
}

void printCirculrLinkedList(Node *Tail)
{
    Node *temp = Tail;

    do
    {
        cout << Tail->data << " ";
        Tail = Tail->next;
    } while (Tail != temp);

    cout << endl;
}

int main()
{
    Node *Tail = NULL;

    // todo : Inserting At End
    insertElement(Tail, 5);
    insertElement(Tail, 8, 5);
    insertElement(Tail, 2, 8);
    insertElement(Tail, 7, 2);

    // todo : Inserting At middle
    insertElement(Tail, 3, 2);

    printCirculrLinkedList(Tail);
    return 0;
}
