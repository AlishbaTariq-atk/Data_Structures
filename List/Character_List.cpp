#include <iostream>
#include <cstring>

using namespace std;

class list
{
    char *arr;
    char *curr;
    int capacity;
    int length;

    public:
        list()
        {

        }
        list(int capacity)
        {
            this->capacity = capacity;
            arr = new char[capacity];
            length = 0;
            curr = arr;
        }
        ~list()
        {
            delete []arr;
        }
        void start()
        {
            curr = arr;
        }
        void tail()
        {
            curr = arr + length - 1;
        }
        void next()
        {
            curr ++;
        }
        void back()
        {
            curr --;
        }
        void insert(char value, int pos)
        {
            if (length == capacity)
            {
                cout << "Capacity reached!" <<endl;
                return;
            }
            if (pos <1 || pos > length +1 )
            {
                cout << "Invalid Position! " << endl;
                return;
            }
            tail();
            for(int i=length ; i>=pos; i--)
            {
                *(curr+1) = *curr;
                back();
            }
            *(curr+1) = value ;
            length++;
        }
        void remove(int pos)
        {
           if (length == 0)
            {
                cout << "Empty!" <<endl;
                return;
            }
            if (pos <1 || pos > length +1 )\
            {
                cout << "Invalid Position! " << endl;
                return;
            }
            start();
            curr = curr + pos -1; 
            for(int i=pos; i < length ; i++)
            {
                *curr = *(curr + 1);
                next();
            }
            length --;
        }
        int find( int value)
        {
            if(length == 0)
            {
                cout << "Empty list!" << endl;
                return -1;
            }
            start();
            for(int i=1; i<= length ; i++)
            {
                if (*curr == value)
                {
                    return i;
                }
                next();
            }
            return -1;
        }
        void print()
        {
            start();
            for(int i=0 ; i < length; i++)
            {
                
                cout << *curr << " " ;
                next();
            }
        }

        char check(int num)
        {
            return *(curr+num);
        }
};

int main()
{
    list name(6);
    char test[6] = {'f','a','r','i','b','a'};
    int steps=0;
    name.insert('e',1);
    name.insert('f',2);
    name.insert('a',3);
    name.insert('b',4);
    name.insert('i',5);
    name.insert('r',6);

    cout << "You have a random letters combination: " << endl;
    name.print();
    cout << "Your goal is to convert this combination into ""fariba"" using insert or remove function in minimum steps. Best of luck! " << endl;
    int option;
    cout << "START: \n1. insert\n 2. remove\n 3.Exit" << endl;
    cin >> option;

while (1)
{
    cout << "START: \n1. insert\n 2. remove\n 3.Exit" << endl;
    cin >> option;
    if (option == 1)
    {
            char value;
            int pos;
            int count=0;
            cout << "Enter value  to insert: ";
            cin >> value;
            cout << "Enter position: " ;
            cin >> pos;
            name.insert(value,pos);
            steps++;
            for(int i=0;i<6;i++)
            {
                if (test[i]!=name.check(i))
                {
                    break;
                }
                else if(test[i]== name.check(i))
                {
                    count++;
                    name.next();
                    continue;
                }
                
            }
            if(count == 6)
            {
                cout << "words matched!" << endl;
                cout << "Steps: " << steps;
                name.print();
                break;
            }
            

        }
    else if (option == 2)
    {
            int count=0;
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            name.remove(pos);
            steps++;
            for(int i=0;i<6;i++)
            {
                if (test[i]!=name.check(i))
                {
                    break;
                }
                else if(test[i]== name.check(i))
                {
                    count++;
                    name.next();
                    continue;
                }
                
            }
            if(count == 6)
            {
                cout << "words matched!" << endl;
                cout << "Steps: " << steps;
                name.print();
                
            }
            


    }
    else 
    return 0;
}
return 0;
}
