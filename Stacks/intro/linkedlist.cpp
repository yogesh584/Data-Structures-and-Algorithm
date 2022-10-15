/*
    STACKS USING LINKED LIST.
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

class Stack
{
private:
    int size;
    Node *head = NULL;
    Node *tail = NULL;
    Node *top = head;

public:
    void push(int givenData)
    {
        Node *temp = new Node(givenData);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }

        temp->next = head;
        head = temp;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack UnderFlow" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;

            temp->next = NULL;
        }
    }

    int peek()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack st;
    st.push(23);
    st.push(2);
    st.push(3);

    st.pop();

    cout << st.peek() << endl;

    cout << st.empty() << endl;

    return 0;
}
