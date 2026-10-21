#include <iostream>
#include <stack>
using namespace std;

int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

int main()
{
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter infix: ";
    cin >> infix;

    for (char ch : infix)
    {
   
        if (isalnum(ch))
        {
            postfix += ch;
        }

        else if (ch == '(')
        {
            s.push(ch);
        }

        else if (ch == ')')
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            s.pop(); 
        }

        else
        {
            while (!s.empty() &&
                   s.top() != '(' &&
                   priority(s.top()) >= priority(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix;

    return 0;
}