#include <iostream>
#include <string>

using namespace std;

class Node 
{
public:
    char data;
    Node* next;

    Node(char value)
    {
        data = value;
        next = NULL;
    }
};

class ListNode 
{
    public:
        char data;
        ListNode* next;
        ListNode* prev;

        ListNode(char value) 
        {
            data = value;
            next = NULL;
            prev = NULL;
        }
};

class Stack 
{
    Node* top;
    int length;
    int capacity;

   public:
    Stack(int capacity) 
    {
        this->capacity = capacity;
        length = 0;
        top = NULL;
    }

    ~Stack() 
    {
        while (!isEmpty()) 
        {
            pop();
        }
    }

    bool isEmpty() 
    {
        return length == 0;
    }

    bool isFull() 
    {
        return length == capacity;
    }

    void push(char value) 
    {
        if (isFull()) {
            return;
        }
        Node* curr = new Node(value);
        curr->next = top;
        top = curr;
        length++;
    }

    char pop() 
    {
        if (isEmpty()) {
            return '\0';
        }
        Node* curr = top;
        top = curr->next;
        char value = curr->data;
        delete curr;
        length--;
        return value;
    }
};

class List 
{
    ListNode* head;
    int length;

   public:
    List() 
    {
        head = NULL;
        length = 0;
    }

    ~List()
    {
        ListNode* curr = NULL;
        while (head != NULL) 
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

    void insert(char value, int pos) 
    {
        if (pos < 1 || pos > length + 1) 
        {
            cout << "Invalid position!" << endl;
            return;
        }
        ListNode* n = new ListNode(value);

        if (pos == 1)
        {
            n->next = head;
            if (head != NULL) 
            {
                head->prev = n;
            }
            head = n;
        } 
        else
        {
            ListNode* curr = head;
            for (int i = 1; i < pos - 1; i++) 
            {
                curr = curr->next;
            }
            n->prev = curr;
            n->next = curr->next;
            if (curr->next != NULL) 
            {
                curr->next->prev = n;
            }
            curr->next = n;
        }
        length++;
    }

    bool isPalindrome(int size) 
    {
        Stack stack(size);

        ListNode* curr = head;
        while (curr != NULL)
        {
            stack.push(curr->data);
            curr = curr->next;
        }

        string palindrome;

        for (int i = 1; i <= size; i++) 
        {
            palindrome += stack.pop();
        }

        curr = head;
        for (int i = 1; i <= size; i++) 
        {
            if (curr->data != palindrome[i - 1]) 
            {
                return false;
            }
            curr = curr->next;
        }

        return true;
    }

    void display() 
    {
        if (length == 0)
        {
            cout << "Nothing added yet!\n" << endl;
            return;
        }
            ListNode* curr = head;
            for (int i = 1; i <= length; i++) 
            {
                cout << curr->data;
                curr = curr->next;
            }
        cout << endl;
    }
};

int main() 
{
    List word;
    int choice;
    char value;
    int size = 0;

    cout << "Palindrome check--\nEnter letters:" << endl;

    for (int i = 1;; i++) 
    {
        cout << "Do you want to enter a value:\n1. Yes\n2. No" << endl;
        cin >> choice;
        if (choice == 2)
        {
            break;
        }
        cout << "Letter " << i << " = ";
        cin >> value;
        word.insert(value, i);
        size++;
    }

    cout << "word = ";
    word.display();
    if (word.isPalindrome(size)) 
    {
        cout << "It is a Palindrome!" << endl;
    } 
    else
    {
        cout << "It is not a Palindrome!" << endl;
    }

    return 0;
}
