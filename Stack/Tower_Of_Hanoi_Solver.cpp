/* 
    NOTE: The code provided is created using some help from websites (like Geekforgeeks.com , stackoverflow.com etc) 
          during my research on Hanoi Problem. 
          The main logic was created by me but pythonTtutor and GPT were used to solve bugs and ehance code efficiency.
*/
#include <iostream> 
#include <cmath>

using namespace std;

class stack
{
    int *arr;
    int capacity;
    int top;

    public:
        stack(int size)
        {
            top = -1;
            capacity = size;
            arr = new int[capacity];
        }
        ~stack()
        {
            delete []arr;
        }
        bool isfull()
        {
            if (top == capacity-1)
            {
                return true;  
            }
            else 
              return false;
        }
        bool isEmpty()
        {
            if(top == -1)
            {
                return true; 
            }
            else 
                return false;
        }
        void push(int value)
        {
            if(isfull())
            {
                cout << "Stack Overflow!" << endl;
                return;
            }
            top++;
            arr[top] = value;
        }
        int pop()
        {
            if(isEmpty())
            {
                cout << "Stack Undeflow!" << endl;
            }
            int value = arr[top];
            top--;

            return value;
        }
        int peek()
        {
            if(isEmpty())
            {
                cout << "Stack Underflow!" << endl;
                return 0;
            }
            int value = arr[top];

            return value;

        }
        void display()
        {
        if(!isEmpty())
        {

            for(int i=0; i<=top; i++)
            {
                cout<< "   " << arr[i]<<endl;
            }
            cout << endl;
        }
        else
        {
            cout << " No disk in Stack!" << endl;
            cout<<endl;
        }

        }

}; 

void moveDisks(stack& a, stack& b,string a_name, string b_name)  //main logic for moving disks between stacks
{
    if(a.isEmpty()) 
    {
        a.push(b.pop());
        cout << "Moved disk " << a.peek() << " from " << b_name << " to " << a_name << endl;
    }
    else if(b.isEmpty()) 
    {
        b.push(a.pop());
        cout << "Moved disk " << b.peek() << " from " << a_name << " to " << b_name << endl;
    }
    else if(a.peek() > b.peek()) 
    {
        a.push(b.pop());
        cout << "Moved disk " << a.peek() << " from " << b_name << " to " << a_name << endl;
    }
    else  //a.peek() < b.peek()
    {
        b.push(a.pop());
        cout << "Moved disk " << b.peek() << " from " << a_name << " to " << b_name << endl;
    }

}

int solveHanoi(int disks) 
{
    stack s1(disks);
    stack s2(disks);
    stack s3(disks);

    for (int i = disks; i >= 1; i--) //populating s1 with all disks
    {
        s1.push(i);
    }

    cout << "Initial stacks are:\n---S1---" << endl;
    s1.display();
    cout << "---S2---" << endl;
    s2.display();
    cout << "---S3---"<< endl;
    s3.display();

    int moves = pow(2, disks) - 1; //formula for calculating total moves (learned from GeeksforGeeks.com)

    for (int i = 1; i <= moves; i++) 
    {
        if (i % 3 == 1)   //Based on theory from geekforgeeks
        {
            if(disks % 2 == 0)   // If number of disks is even, swap s2 and s3 to ensure correct moves between stacks (formula learned from stackoverflow.com)
            {
                moveDisks(s1, s2, "S1", "S2");
            }
            else
            {
                moveDisks(s1, s3, "S1", "S3");
            }
        }
        else if (i % 3 == 2) 
        {
            if(disks % 2 == 0)
            {
                moveDisks(s1, s3, "S1", "S3");
            }
            else
            {
                moveDisks(s1, s2, "S1", "S2");
            }
        }
        else 
        {
            if(disks % 2 == 0)
            {
                moveDisks(s3, s2, "S3", "S2");
            }
            else
            {
                moveDisks(s2, s3, "S2", "S3");
            }
        }

        cout << "---S1---" << endl;
        s1.display();
        cout << "---S2---" << endl;
        s2.display();
        cout << "---S3---"<< endl;
        s3.display();
        
    }
    return moves;
}

int main() 
{
    int disks;

    cout << "Enter the number of disks: ";
    cin >> disks;
    cout << endl;
    if(disks <= 0)
    {
        cout << "Kindly enter valid number of disks (more than 0)" << endl;
        return 0;
    }
    else
    {
        int moves = solveHanoi(disks);
        cout << "\nThe Tower of Hanoi for " << disks << " disks was solved in " << moves << " moves." << endl;
    }
    
    return 0;
}
