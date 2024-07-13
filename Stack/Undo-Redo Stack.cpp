#include <iostream>

using namespace std;

class node
{
    public:
        char data;
        node *next;
    node(char value)
    {
        data = value;
        next = NULL;
    }
        
};

class stack
{
    node *top;
    int length;
    int capacity;

    public:
        stack(int capacity)
        {
            this->capacity = capacity;
            length = 0;
            top = NULL;
        }
        ~stack()
        {
            while(!isEmpty())
            {
                pop();
            }
        }
        bool isEmpty()
        {
            if(length == 0)
            {
                cout << "Stack underflow!" << endl;
                return true;
            }
            else
                return false;
        }
        bool isFull()
        {
            if(length == capacity)
            {
                cout << "Stack overflow!" << endl;\
                return true;
            }
            else 
                return false;
        }
        void push(char value)
        {
             if (isFull())
            {
                return;
            }
            node *curr = new node(value);
            curr->next = top;
            top = curr;
            node *n = top;
            curr->next = n->next;
            length++;
            return;

        }
        char pop()
        {
            if(isEmpty())
            {
                return '\0';
            }
            node *curr = top;
            top = curr->next;
            char value = curr->data;
            delete curr;
            curr = NULL;
            length--;
            return value;
        }  
        void display()
        {
           if(!isEmpty())
           {
            string word[length];
            node *curr = top;
            cout << "Your  string is: " ;
            for(int i=length-1; i>=0; i--)
            {
                word[i]= curr->data;
                curr = curr->next;
                
            } 
            for(int i=0; i<length; i++)
            {
                cout << word[i] << " ";
            } 

            cout << endl;
           } 
           else
           {
            cout << "Stack is empty!" << endl;
           } 
        }  

};


int main()
{
    int length;
    cout << "Enter length of the the string you will enter : " ;
    cin >> length;

    string input;
    stack s1(length);
    stack s2(length);

    cout << "\nEnter the string:  ";
    getline(cin >> ws, input);

    for(int i=0; i< length; i++)
    {
        s1.push(input[i]);
    }

    //cout << "String is: " ;
    s1.display();
    int option;

    while(option!=3)
    {
        cout << "Menu: \n 1. Undo\n 2. Redo\n 3.Exit" << endl;
        cin >> option;
        
        switch(option)
        {
            case 1:
            {
                if (!s1.isEmpty())
                {
                    //cout<<s1.pop()<<endl;
                    s2.push(s1.pop());
                    s1.display();
                }
                break;
            }
            case 2:
            {
                s1.push(s2.pop());
                s1.display();
                break;
            }
            case 3:
            {
                break;
            }
        }
    }

    return 0;
}
