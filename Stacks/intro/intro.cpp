/*
    INTRO TO STACKS.
        WHAT IS STACK : A LIFO DATA STRUCTURE.
        OPERATIONS IN STACK :(ONLY IMPORTANT)
            1. PUSH
            2. POP
            3. TOP
            4. EMPTY
            5. SIZE

        CREATING STACK USING ARRAYS.
*/

#include <iostream>
using namespace std;

class stack
{

private:
    int size;
    int *arr;
    int top;

public:
    stack(int givenSize)
    {
        this->size = givenSize;
        arr = new int[givenSize];
        top = -1;
    }

    void push(int elem)
    {
        if (top < size)
        {
            top++;
            arr[top] = elem;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    cout << "Top of the Stack is : " << st.peek() << endl;

    st.pop();
    st.pop();

    cout << "Top of the Stack is : " << st.peek() << endl;

    if (st.empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is Not Empty" << endl;
    }

    return 0;
}
