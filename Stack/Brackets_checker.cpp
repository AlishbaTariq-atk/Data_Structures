#include <iostream>
#include <stack>

using namespace std;

bool isFirst_Bracket(char c)
{
    if(c == '(' || c == '[' || c == '{')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isLast_Bracket(char c)
{
    if(c == ')' || c == ']' || c == '}')
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool bracket_check(string exp)
{
    stack<int> s;

    for(int i = 0 ; i < exp.length(); i++)
    {
        if(isFirst_Bracket(exp[i]))
        {
            s.push(exp[i]);
        }
        else if(isLast_Bracket(exp[i]))
        {
            if(s.empty())
            {
                return false;
            }
            char first_bracket = s.top(); 
            
            if(exp[i] == ')')
            {
                if(first_bracket == '(')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(exp[i] == ']')
            {
                if(first_bracket == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(exp[i] == '}')
            {
                if(first_bracket == '{')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }

            
        }
    }
    if(!s.empty())  //even after popping  all corresponding brackets, any bracket left in stack
    {
        return false;
    }

    return true;
}

int main()
{
    string expression;

    cout << "Enter expression to check for any missing brackets error: " << endl;
    getline(cin >> ws, expression);

    if(bracket_check(expression))
    {
        cout << "No error found!" << endl;
    }
    else
    {
        cout << "Error : Bracket(s) missing!" << endl;
    }

    return 0;
}