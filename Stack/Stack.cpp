#include <iostream>

using namespace std;

class stack
{
    char *arr;
    int capacity;
    int top;

    public:
        stack(int size)
        {
            top = -1;
            capacity = size;
            arr = new char[capacity];
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
        void push(char value)
        {
            if(isfull())
            {
                cout << "Stack Overflow!" << endl;
                return;
            }
            top++;
            arr[top] = value;
        }
        char pop()
        {
            if(isEmpty())
            {
                cout << "Stack Undeflow!" << endl;
                return '\0';
            }
            char value = arr[top];
            top--;

            return value;
        }
        char peek()
        {
            if(isEmpty())
            {
                cout << "Stack Underflow!" << endl;
                return 0;
            }
            char value = arr[top];

            return value;

        }
        void display()
        {
        if(!isEmpty())
        {
        //cout<<"Stack elements: "<<endl;
        for(int i=0; i<=top; i++)
        {
            cout<<arr[i]<< " ";
        }
        cout<<endl;
        }

        }

};       

int main()
{
   int length;
   string word ;

   cout << "Enter the length of word you will enter: ";
   cin >> length;
   stack old(length);

   cout << "Enter the word: ";
   getline( cin >> ws, word);

   for(int i=0 ; i< length; i++)
   {
        old.push(word[i]);
   }

   cout << "\nOriginal string is: ";
    old.display();

   // stack reverse(length);


    // for(int i=0 ; i<length; i++)
    // {
    //     reverse.push(old.pop());
    // }

    // cout << "\nReversed string is: "; 
    // reverse.display(); 

    string new_word;

    for(int i=0;i<length;i++)
    {
        new_word+=old.pop();
    }
    cout << "Reversed string is : " << new_word << endl;
    



    return 0;
}