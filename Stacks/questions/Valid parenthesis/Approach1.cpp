/*
    VALID PARENTHESIS
        APPROACH 1 :
*/
#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string expression)
{

    stack<char> s;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
        {
            // opening bracket
            s.push(expression[i]);
        }
        else
        {
            // closing breaket
            if (!s.empty())
            {
                char top = s.top();
                char ch = expression[i];
                if (((ch == '}') && (top == '{')) || ((ch == ']') && (top == '[')) || ((ch == ')') && (top == '(')))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << endl
         << endl
         << endl;

    string expression = "{([])}";
    if (isValidParenthesis(expression))
    {
        cout << "Valid Parenthisis" << endl;
    }
    else
    {
        cout << "Invalid Parenthisis" << endl;
    }

    cout << endl
         << endl
         << endl;
    return 0;
}
