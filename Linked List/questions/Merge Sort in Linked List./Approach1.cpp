/*
    MEARGE SORT IN LINKED LIST.
        LECTURE 53 :
            LINK : https://youtu.be/rM5EEA_rbNY

        APPROACH 1 :
            (DATA REPLACEMENT IS NOT ALLOWED)
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

/*      FINDING MID      */
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/*      MERGING TWO SORTED LINKED LIST      */
Node *merge(Node *leftHead, Node *rightHead)
{
    if (leftHead == NULL)
    {
        return rightHead;
    }

    if (right == NULL)
    {
        return leftHead;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (leftHead != NULL && rightHead != NULL)
    {
        if (leftHead->data < rightHead->data)
        {
            temp->next = leftHead;
            temp = leftHead;
            leftHead = leftHead->next;
        }
        else
        {
            temp->next = rightHead;
            temp = rightHead;
            rightHead = rightHead->next;
        }
    }

    while (leftHead != NULL)
    {
        temp->next = leftHead;
        temp = leftHead;
        leftHead = leftHead->next;
    }

    while (rightHead != NULL)
    {
        temp->next = rightHead;
        temp = rightHead;
        rightHead = rightHead->next;
    }

    ans = ans->next;
    return ans;
}

/*      MERGE SORT      */
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    /*      FINDING MID      */
    Node *mid = findMid(head);

    /*      BREAKING LINKED LIST INTO TWO PARTS     */
    Node *leftHead = head;
    Node *rightHead = mid->next;
    mid->next = NULL;

    /*      SORTING LEFT PART       */
    leftHead = mergeSort(leftHead);

    /*      SORTING RIGHT PART       */
    rightHead = mergeSort(rightHead);

    /*      MERGE BOTH LEFT AND RIGHT HALVES        */
    Node *result = merge(leftHead, rightHead);
    return result;
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
    insertAtTail(tail, 5);
    insertAtTail(tail, 8);
    insertAtTail(tail, 2);
    insertAtTail(tail, 4);

    /*      PRINTING LINKED LIST        */
    printLinkedList(head);

    /*      SORTING LINKED LIST         */
    mergeSort(head);

    /*      PRINTING LINKED LIST        */
    printLinkedList(head);

    cout << endl
         << endl;
    return 0;
}
