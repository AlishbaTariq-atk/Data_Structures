#include <iostream>
using namespace std;

class HashTable
{
    int * table;
    int length;
    int capacity;

    public:
    HashTable(int capacity)
    {
        table = new int[capacity];
        length = 0;
        this->capacity = capacity;
        //filling the table with -1;
        for(int i = 0; i<capacity ; i++)
        {
            table[i] = -1;
        }
    }
    ~HashTable()
    {
        delete [] table;
    }
    void insert(int value)
    {
        //if 70% of the table is filled then go for rehashing
        if((float(length) / float(capacity)) >= 0.7)
        {
            cout << "70% Table filled! Applying Rehashing" << endl;
            rehash();
        }
        //inserting value
        int index = value % capacity; //hash function
        while (table[index] != -1 )
        {
            index = (index + 1) % capacity; //linear probing in case of collision
        }
        table[index] = value;
        length ++;
    }
    void rehash()
    {
        //storing existing table before rehashing
        int *arr = table;

        capacity = capacity *2; //doubling the capacity;
        table = new int[capacity];
        for (int i = 0; i < capacity; i++) 
        {
            table[i] = -1;
        }
        //filling the table with existing values while rehashing
        for(int i=0 ; i< capacity/2; i++)
        {
            if(arr[i] != -1)
            {
                insert(arr[i]);
            }   
        }
        delete [] arr;
    }
    void print ()
    {
        if(length == 0)
        {
            cout << "No value added to Hash Table yet!" <<endl;
            return;
        }
        cout << "Hash Table: " << endl;
        for(int i =0 ; i < capacity; i++)
        {
            if(table[i] != -1)
            {
                cout << i << ": " << table[i] << endl;
            }
        }

    }

};

int main()
{
    int option, value;
    HashTable h(5); //starting with initial size 5
    while(option !=2)
    {
        cout << "Do you want to enter value?\n 1. Yes\n 2. NO?" << endl;
        cin >> option;
        switch (option)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                h.insert(value);
                break;
            case 2:
                h.print();
                return 0;    
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    }

    return 0;
}