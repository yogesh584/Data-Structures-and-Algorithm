/*
    REMOVE DUPLICATES FROM UNSORTED LINKED LIST.
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

void deleteDuplicateNodes(Node *head, int givenData)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr != NULL)
    {
        if (curr->data == givenData)
        {
            prev->next = curr->next;
            Node *temp = curr->next;
            curr->next = NULL;
            curr = temp;
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
        }
    }
}

void removeDuplicateElements(Node *head)
{
    while (head != NULL)
    {
        deleteDuplicateNodes(head, head->data);
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
    insertAtTail(tail, 3);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);

    /*      PRINTING AND SORTING 0S 1S AND 2S      */
    printLinkedList(head);

    removeDuplicateElements(head);

    printLinkedList(head);
    return 0;
}
