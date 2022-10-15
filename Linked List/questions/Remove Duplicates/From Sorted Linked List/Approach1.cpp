/*
    REMOVE DUPLICATES FROM SORTED LINKED LIST
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

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            // delete (nodeToDelete);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    /*      INSERTING DATA TO LINKED LIST       */
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 4);
    insertAtTail(tail, 6);
    insertAtTail(tail, 6);

    /*      PRINTING AND SORTING 0S 1S AND 2S      */
    printLinkedList(head);

    head = removeDuplicates(head);

    printLinkedList(head);
    return 0;
}
