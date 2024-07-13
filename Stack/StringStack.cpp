#include <iostream>

using namespace std;

class stack
{
    string *arr;
    int capacity;
    int top;

    public:
        stack(int size)
        {
            top = -1;
            capacity = size;
            arr = new string[capacity];
        }
        ~stack()
        {
            delete []arr;
        }
        bool isfull()
        {
            if (top == capacity-1)
            {
                cout << "Stack is full! " << endl;
                return true;  
            }
            else 
              return false;
        }
        bool isEmpty()
        {
            if(top == -1)
            {
                cout << "Stack is empty!" << endl;
                return true; 
            }
            else 
                return false;
        }
        void push(string value)
        {
            if(isfull())
            {
                cout << "Stack Overflow!" << endl;
                return;
            }
            top++;
            arr[top] = value;
        }
        string pop()
        {
            if(isEmpty())
            {
                cout << "Stack Undeflow!" << endl;
            }
            string value = arr[top];
            top--;

            return value;
        }
        string peek()
        {
            if(isEmpty())
            {
                cout << "Stack Underflow!" << endl;
                return 0;
            }
            string value = arr[top];

            return value;

        }
        void display()
        {
        if(!isEmpty())
        {
        cout<<"Stack elements: "<<endl;
        for(int i=0; i<=top; i++)
        {
            cout<<arr[i]<<endl;
        }
        cout<<endl;
        }

        }

};       

int main()
{
    string num1;
    string num2;

    stack swap(2);

    cout << "Enter 2 number: \nNum1= ";
    getline(cin >> ws, num1);
    cout << "\nNum2= ";
    getline ( cin >> ws, num2);

    swap.push(num1);
    swap.push(num2);

    cout << "The original number were: " << endl;
    swap.display();


    num1 = swap.pop();
    num2 = swap.pop();

    cout << "Swapped numbers are: \n Num1=  " << num1 << "\n Num2= "<< num2 << endl;


    return 0;
}