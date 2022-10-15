/*
    REVERSE A LINKED LIST IN K ORDER
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
Node *ReverseLinkedListInKOrder(Node *head, int k)
{
    // Base Case
    if (head == NULL)
    {
        return NULL;
    }

    Node *forward = NULL;
    Node *current = head;
    Node *previous = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
        count++;
    }
    if (forward != NULL)
    {
        head->next = ReverseLinkedListInKOrder(forward, k);
    }
    return previous;
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

    Head = ReverseLinkedListInKOrder(Head, 3);
    printLinkedList(Head);

    return 0;
}