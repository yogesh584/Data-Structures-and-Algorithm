/*
    MEARGE TWO SORTED LINKED LIST.
        APPROACH 1 :  (OPTIMIZED APPROACH)
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

Node *solve(Node *first, Node *second)
{
    /*      IF ONLY ONE ELEMENT IN LINKED LIST 1         */
    if (first->next == NULL)
    {
        first->next = second;
    }

    Node *curr1 = first;
    Node *forward1 = curr1->next;
    Node *curr2 = second;
    Node *forward2 = curr2->next;

    while (forward1 != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= forward1->data)
        {
            curr1->next = curr2;
            forward2 = curr2->next;
            curr2->next = forward1;

            curr1 = curr2;
            curr2 = forward2;
        }
        else
        {
            curr1 = forward1;
            forward1 = forward1->next;

            if (forward1 == NULL)
            {
                curr1->next = curr2;
            }
        }
    }

    return first;
}

/*      MERGING TWO SORTED LINKED LIST      */
Node *SortTwoLinkedList(Node *first, Node *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data <= second->data)
        return solve(first, second);
    else
        return solve(second, first);
}

int main()
{
    Node *node1 = new Node(1);
    Node *head1 = node1;
    Node *tail1 = node1;

    Node *node2 = new Node(1);
    Node *head2 = node2;
    Node *tail2 = node2;

    /*      INSERTING DATA TO LINKED LIST 1       */
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);

    /*      INSERTING DATA TO LINKED LIST 2       */
    insertAtTail(tail2, 2);
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 5);

    /*      PRINTING FIRST LIST        */
    printLinkedList(head1);

    /*      PRINTING SECOND LIST        */
    printLinkedList(head2);

    /*      MERGING TWO SORTED LINKED LIST      */
    head1 = SortTwoLinkedList(head1, head2);

    /*      PRINGING MERGED SORTED LINKED LIST      */
    printLinkedList(head1);
    return 0;
}
