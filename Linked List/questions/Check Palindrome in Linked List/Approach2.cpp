/*
    CHECK PALINDROME IN LINKED LIST.
        APPROACH 1 :
            STEP 1 : FIND MIDDLE. (TO FIND MIDDLE WE CAN USE SLOW AND FAST POINTERS)
            STEP 2 : REVERSE LINKED LIST AFTER MIDDLE.
            STEP 3 : COMPARE BOTH HALF PARTS.
            STEP 4 : REVERSE LINKED LIST AFTER MIDDLE. (TO CHANGE LINKED LIST TO ITS PREVIOUS STATE (DEFAULT STATE)).
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

/*      FINDING MIDDLE OF LINKED LIST       */
Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

/*      REVERSING LINKED LIST       */
Node *reverseOfLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

/*      FUNCTION TO CHECK PAINDROME        */
bool checkPalindrome(Node *head)
{
    /*      CHECKING IS LIST EMPTY OF HAVE SINGLE ELEMENT       */
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    /*      FINDING MIDDLE OF LINKED LIST       */
    Node *mid = getMid(head);

    /*      REVERSE LINKED LIST AFTER MIDDLE        */
    Node *temp = mid->next;
    mid->next = reverseOfLinkedList(temp);

    /*      COMPARE BOTH HALF PARTS        */
    Node *head1 = head;
    Node *head2 = mid->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    /*      REVERSE LINKED LIST AFTER MIDDLE.       */
    temp = mid->next;
    mid->next = reverseOfLinkedList(temp);

    return true;
}

int main()
{
    cout << endl
         << endl
         << endl;
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    /*      INSERTING DATA TO LINKED LIST       */
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);

    /*      PRINTING LINKED LIST        */
    printLinkedList(head);
    cout << endl
         << endl;

    /*      CHECKING PAILNDROME     */
    if (checkPalindrome(head))
    {
        cout << "Palindrome " << endl;
    }
    else
    {
        cout << "Not Palindrome " << endl;
    }

    /*      PRINTING LINKED LIST        */
    printLinkedList(head);

    cout << endl
         << endl
         << endl;
    return 0;
}
