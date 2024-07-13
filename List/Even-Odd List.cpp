#include <iostream>
#include <cstring>

using namespace std;

class list
{
    int *arr;
    int *curr;
    int capacity;
    int length;

public:
    list(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        length = 0;
        curr = arr;
    }

    ~list()
    {
        delete[] arr;
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
        curr++;
    }

    void back()
    {
        curr--;
    }

    void insert(int value, int pos)
    {
        if (length == capacity)
        {
            cout << "Capacity reached!" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position! " << endl;
            return;
        }

        tail();

        for (int i = length; i >= pos; i--)
        {
            *(curr + 1) = *curr;
            back();
        }

        *(curr + 1) = value;
        length++;
    }

    int* find_even(int *curr)
    {
        int *even = curr;
        int pos = find(*curr);

        for (int i = pos; i <= length; i++)
        {
            if (*even % 2 == 0)
            {
                return even;
            }
            even++;
        }
        return NULL;
    }

    int* find_odd(int *curr)
    {
        int *odd = curr;
        int pos = find(*curr);

        for (int i = pos; i <= length; i++)
        {
            if (*odd % 2 != 0)
            {
                return odd;
            }
            odd++;
        }
        return NULL;
    }

    void rearrangeList()
    {
        start();
        int *even = NULL;
        int *odd = NULL;
        int temp = 0;
        int count = 1;

        if (*curr % 2 != 0) // first digit odd
        {
            even = find_even(curr);
            if (even) 
            {
                temp = *even; // swapping even digit to first position
                *even = *curr;
                *curr = temp;
            }
        }

        while (count < length)
        {
            next();

            if (count % 2 != 0) // if count odd find odd digit
            {
                odd = find_odd(curr);
                if (odd) 
                {
                    temp = *odd; // swapping odd digit to curr position
                    *odd = *curr;
                    *curr = temp;
                }
            }
            else // count even place even digit
            {
                even = find_even(curr);
                if (even) {
                    temp = *even; // swapping even digit to curr position
                    *even = *curr;
                    *curr = temp;
                }
            }
            count++;
        }
    }

    int find(int value)
    {
        if (length == 0)
        {
            cout << "Empty list!" << endl;
            return -1;
        }
        start();

        for (int i = 1; i <= length; i++)
        {
            if (*curr == value)
            {
                return i;
            }

            if (i < length) // Move to the next element if not at the end
            {
                next();
            }
        }

        return -1; // Element not found
    }

    void print()
    {
        start();
        for (int i = 1; i <= length; i++)
        {
            cout << *curr << " ";
            next();
        }
    }
};

int main()
{
    // list l(9);
    // l.insert(5, 1);
    // l.insert(2, 2);
    // l.insert(9, 3);
    // l.insert(4, 4);
    // l.insert(7, 5);
    // l.insert(6, 6);
    // l.insert(1, 7);
    // l.insert(3, 8);
    // l.insert(8, 9);

    int value;
    int size;
     
    cout << "Enter the size of list: ";
    cin >> size;
    list l(size);

    cout << "Enter values:" << endl;

    for(int i = 1; i <= size; i++)
    {
        cout << "Pos " << i  << ": ";
        cin >> value;
        l.insert(value, i);
    }

    cout << "Original list:\n";
    l.print();

    l.rearrangeList();
    cout << "\nRearranged list(even-odd):\n";
    l.print();

    return 0;
}
