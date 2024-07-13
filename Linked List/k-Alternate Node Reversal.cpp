#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class list
{
public:
    node* head;

public:
    list()
    {
        head = nullptr;
    }

    void insert(int data)
    {
        node* newNode = new node(data);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            node* current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    node* kAltReverse(node* head, int k)
    {
        node* current = head;
        node* next;
        node* prev = nullptr;
        int count = 0;

        while (current != NULL && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (head != NULL)
        {
            head->next = current;
        }

        count = 0;
        while (count < k - 1 && current != NULL)
        {
            current = current->next;
            count++;
        }

        if (current != NULL)
        {
            current->next = kAltReverse(current->next, k);
        }

        return prev;
    }

    void display()
    {
        node* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    
    list l;
    int k;
    for (int i = 1; i <= 9; i++)
    {
        l.insert(i);
    }

    cout << "Original: ";
    l.display();

    cout << "\nEnter k for which the nodes are to be reversed: ";
    cin >> k;

    node* current = l.kAltReverse(l.head, k); 

    cout << "\nLinked List after reversing alternate groups of " << k << " nodes: \n";

    // Print the reversed list
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}


