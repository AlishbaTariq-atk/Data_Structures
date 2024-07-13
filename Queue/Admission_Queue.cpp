#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

class student
{
public:
    string name;
    int merit;
    student() 
    {

    }
    student(string name, int merit)
    {
        this->name = name;
        this->merit = merit;
    }
};

class node
{
public:
    student s;
    node *next;
    
    node(string name, int merit) : s(name, merit)
    {
        next = NULL;
    }
};

class queue
{
    int length;
    node *front;
    node *rear;
    bool processed; 

public:
    queue()
    {
        length = 0;
        front = NULL;
        rear = NULL;
        processed = false; 
    }

    ~queue()
    {
        node *curr = NULL;
        while (front != NULL)
        {
            curr = front;
            front = front->next;
            delete curr;
        }
    }

    bool isEmpty()
    {
        return length == 0;
    }

    int getlength()
    {
        return length;
    }

    bool isProcessed() const
    {
        return processed;
    }

    void markProcessed()
    {
        processed = true;
    }

    void enqueue(string name, int merit)
    {
        node *n = new node(name, merit);
        if (front == NULL)
        {
            front = n;
            rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }

        length++;
        return;
    }

    node *dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return NULL;
        }
        node *n = new node(front->s.name,front->s.merit);
        node *curr = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL; 
        }
        delete curr;
        length--;
        return n;
    }

    void get_front()
    {
        if (isEmpty())
        {
            cout << "No student in queue!" << endl;
            return;
        }
        cout << front->s.name << " --- " << front->s.merit << endl;
        return;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No student in queue!" << endl;
            return;
        }
        cout << "Total students: " << length << endl;
        node *index = front;
        for (int i = 1; i <= length; i++)
        {
            cout << i << ". " << index->s.name << " --- " << index->s.merit << endl;
            index = index->next;
        }
        cout << endl;
        return;
    }
};

queue *smallest(queue &q1, queue &q2, queue &q3)
{
    if (!q1.isEmpty() && !q1.isProcessed())
    {
        if ((!q2.isEmpty() && q2.getlength() < q1.getlength()) || (q2.getlength() == q1.getlength() && rand() % 2 == 0)) //rand() for the condition when 2 queues have same length 
        {
            return &q2;
        }
        else if ((!q3.isEmpty() && q3.getlength() < q1.getlength()) || (q3.getlength() == q1.getlength() && rand() % 2 == 0))
        {
            return &q3;
        }
        return &q1;
    }

    if (!q2.isEmpty() && !q2.isProcessed())
    {
        if ((!q3.isEmpty() && q3.getlength() < q2.getlength()) || (q3.getlength() == q2.getlength() && rand() % 2 == 0))
        {
            return &q3;
        }
        return &q2;
    }

    if (!q3.isEmpty() && !q3.isProcessed())
    {
        return &q3;
    }

    // If all queues are processed or empty, return the first one
    return &q1;
}

void process(queue &q1, queue &q2, queue &q3)
{
    while (!q1.isEmpty() || !q2.isEmpty() || !q3.isEmpty())
    {
        queue *smallestQueue = smallest(q1, q2, q3);
        if (smallestQueue->isProcessed())  // If the smallest queue is processed, continue to the next iteration
        {
            continue;
        }
        while (!smallestQueue->isEmpty())
        {
            node *n = smallestQueue->dequeue();

            if (n != NULL)
            {
                if (n->s.merit > 50)
                {
                    cout << n->s.name << " --- " << n->s.merit << " --- " << "Admitted" << endl;
                }
                else
                {
                    cout << n->s.name << " --- " << n->s.merit << " --- " << "NOT Admitted..Better luck next time!" << endl;
                }
            }
        }
        smallestQueue->markProcessed();  // Mark the queue as processed after processing all students
    }
    cout << "\nAll queues processed!" << endl;
}


int main()
{
    srand(time(NULL));
    queue q1, q2, q3;
    int option = 0;
    string name;
    int merit;

    while (option != 5)
    {
        cout << "Enter your choice:\n"
             << " 1. Add student to Queue.\n"
             << " 2. Process Admissions.\n"
             << " 3. Check Queue Status.\n"
             << " 4. See who is next \n"
             << " 5. Exit" << endl;
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
        {
            cout << "Enter Student's\nName: ";
            getline(cin >> ws, name);
            cout << "Merit: ";
            cin >> merit;
            queue *q = smallest(q1, q2, q3);
            if (q != NULL)
            {
                q->enqueue(name, merit);
            }
            break;
        }
        case 2:
        {
            cout << "Admission Processing begins..." << endl;
            process(q1, q2, q3);
            break;
        }
        case 3:
        {
            cout << "STATUS OF QUEUES: \n"
                 << "Name --- Merit" << endl;
            cout << "Queue 1: " << endl;
            q1.display();
            cout << "\nQueue 2: " << endl;
            q2.display();
            cout << "\nQueue 3: " << endl;
            q3.display();
            break;
        }
        case 4:
        {
            cout << "Checking who is next from\n1. Queue 1\n2. Queue 2\n3. Queue 3" << endl;
            cin >> option;
            if (option == 1)
            {
                q1.get_front();
            }
            else if (option == 2)
            {
                q2.get_front();
            }
            else if (option == 3)
            {
                q3.get_front();
            }
            else
            {
                cout << "Enter a valid option!" << endl;
            }
            break;
        }
        case 5:
            break;
        default:
            cout << "Enter a valid option!" << endl;
            break;
        }
    }

    return 0;
}
