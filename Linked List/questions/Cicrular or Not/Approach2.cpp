/*
    FLOYD CYCLE DETECTION ALGO
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

Node *floydCycleDetection(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return slow;
    }

    return NULL;
}

Node *findSartingNodeOfLoop(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *meet = floydCycleDetection(head);
    Node *temp = head;

    while (temp != meet)
    {
        temp = temp->next;
        meet = meet->next;
    }

    return temp;
}

int main()
{
    Node *node1 = new Node(15);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 45);
    insertAtTail(tail, 23);
    insertAtTail(tail, 68);
    insertAtTail(tail, 28);
    insertAtTail(tail, 6);

    tail->next = head->next;

    Node *meet = floydCycleDetection(head);
    if (meet == NULL)
    {
        cout << "No Loop is present" << endl;
    }
    else
    {
        cout << "meet point is : " << meet->data << endl;
        Node *BegginingOfLoop = findSartingNodeOfLoop(head);
        cout << "Starting of loop is : " << BegginingOfLoop->data << endl;
    }

    return 0;
}
