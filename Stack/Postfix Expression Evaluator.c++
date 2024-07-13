#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

bool isDigit(char op)
{
    if(op >= '0' && op <= '9') //ASCII values for 0 to 9 digits
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool isOperator(char op)
{
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^') //possible operators in an expression
    {
        return true;
    } 
    else 
    {
        return false;
    }
}
int operation(char operat, int operand_1, int operand_2)
{
    switch(operat)
    {
        case '+':
        {
            return operand_2 + operand_1; //popping from stack reverses the operands
        }
        case '-':
        {
            return operand_2 - operand_1;
        }
        case '*':
        {
            return operand_2 * operand_1;
        }
        case '/':
        {
            return operand_2 / operand_1;
        }
        case '^':
        {
            return int(pow(operand_2, operand_1));
        }
        default:
        {
            cout << "Invalid input!" << endl;
            return 0;
        }
    }
}
int postfix_result(string exp)
{
    stack<int> s;

    for(int i = 0; i < exp.length(); i++)
    {
        if(exp[i] == ' ') //refering to the space after operand
        {
            continue;
        }
        else if(isOperator(exp[i]))
        {
            int operand_1 = s.top();
            s.pop();
            int operand_2 = s.top();
            s.pop();

            int result = operation(exp[i], operand_1, operand_2);

            s.push(result);
        }
        else if(isDigit(exp[i]))
        {
            int operand = 0;

            while(i < exp.length() && isDigit(exp[i])) //get operand untill non-digit iteration received
            {
                operand = (operand * 10) + (exp[i] - '0'); //getting the multi-digit operands 
                i++;
            }
            i--; //moving one step back so that we dont miss the non-digit iteration as i++ in last iteration happened;
            s.push(operand);
        }
    }
    return s.top();
}


int main()
{
    string expression;

    cout << "Enter the postfix expression that MUST contain a space after every operand:" << endl;
    getline(cin >> ws, expression);

    int result = postfix_result(expression);

    cout << "The postfix expression: " << expression << endl;
    cout << "Output = " << result;

    return 0;
}