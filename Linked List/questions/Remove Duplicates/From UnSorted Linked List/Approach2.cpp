/*
    REMOVE DUPLICATES FROM LINKED LIST.
        APPROACH 2 :
            STEP 1 : SORT THE LINKED LIST. (USING MERGE SORT)
            STEP 2 : REMOVE DUPLICATES
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

/* REMOVING DUPLICATES */
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
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 6);
    insertAtTail(tail, 4);
    insertAtTail(tail, 6);

    /*      PRINTING LINKED LIST      */
    printLinkedList(head);

    /*      SORTING LINKED LIST       */
    mergeSort(head);

    /*      REMOVING DUPLICATES       */
    head = removeDuplicates(head);

    /*      PRINTING LINKED LIST      */
    printLinkedList(head);
    return 0;
}
