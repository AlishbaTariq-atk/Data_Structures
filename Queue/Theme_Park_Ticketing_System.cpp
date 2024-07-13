#include <iostream> 

using namespace std;

class node
{
    public:
        string data;
        node *next;

        node(string value)
        {
            data = value;
            next = NULL;
        }    
};

class queue
{
    int length;
    node *front;
    node *rear;

    public:
        queue()
        {
            length = 0;
            front = NULL;
            rear = NULL;

        }
        ~queue()
        {
            node *curr = front;
            while(front != NULL)
            {
                curr = front;
                front = front->next;
                delete curr;
            }
        }
        bool isEmpty()
        {
            if(length == 0)
            {
                return true;
            }
            else
                return false;
        }
        void enqueue(string value)
        {
            node *n = new node(value);
            if(front == NULL)
            {
                front = n;
                rear = n;  
            }
            else
            {
                rear->next = n;
                rear = n;
            }
                
                length ++;
                return;
        }
        string dequeue()
        {
            if(isEmpty())
            {
                cout << "Queue Underflow!" << endl;
                return "NO visitor";
            }
                string value = front->data;
                node *curr = front;
                front = front->next;
                delete curr;
                length --;
            return value;
        }
        string get_front()
        {
            return front->data;   
        }
        void display()
        {
            if(isEmpty())
            {
                cout << "No member on list!" << endl;
                return;
            }
            node *index = front;
            for(int i = 0; i < length; i++)
            {
                cout << i+1 << ". " << front->data << endl;
                if(index->next = NULL)
                {
                    index = front;
                }
                else 
                {
                    index = index->next;
                }
            }
            cout << endl;
            return;
        }
        void process(string attraction)
        {
            for(int i = 0; i < length ; i++)
            {
                if(isEmpty())
                {
                    cout << "No visitior in list " << endl;
                    return;
                }
                string name = dequeue();
                cout << "Visitor " << name << " now enjoying at " << attraction << endl;   
            }
            return;
        }

};

int main()
{
    queue ticket;
    queue RollerCoaster;
    queue MotionRide;
    queue RoundWheel;
    int option = 0;
    string name;

    while(option != 4)
    {
        cout << "Enter your choice:\n"
             << " 1. Enter visitor to tickets purchase queue.\n"
             << " 2. Sell a ticket.\n"
             << " 3. Process all queues.\n"
             << " 4. Exit " << endl;
        cin >> option;

        switch(option)
        {
            case 1:
            {
                cout << "Enters visitor's name: ";
                getline(cin >> ws, name);

                ticket.enqueue(name);
                cout << "   Visitor added!" << endl;
                break;
            }
            case 2:
            {
                int attraction;
                if(ticket.isEmpty())
                {
                    cout << "No visitor in the waiting list." << endl;
                    break;
                }
                name = ticket.dequeue();
                cout << "Selling ticket to " << name << ":" << endl;
                    cout << "\n Attraction Menu\n"
                        << " 1. Roller Coaster\n"
                        << " 2. Motion Ride\n"
                        << " 3. Round Wheel" << endl;
                    cin >> attraction;

                    if(attraction == 1)
                    {
                        RollerCoaster.enqueue(name);
                        cout << "Ticket sold to " << name << " for Roller Coaster ride " << endl;
                        break;
                    }  
                    else if(attraction == 2)
                    {
                        MotionRide.enqueue(name);
                        cout << "Ticket sold to " << name << " for Motion ride " << endl;
                        break;
                    } 
                    else if(attraction == 3)
                    {
                        RoundWheel.enqueue(name);
                        cout << "Ticket sold to " << name << " for Round Wheel " << endl;
                        break;
                    } 
                    break;
            }     
            case 3:
            {
                RollerCoaster.process("Roller Coaster");
                MotionRide.process("Motion Ride");
                RoundWheel.process("Round Wheel");
                break;
            }
            default:
                break;
        }
    }    

    return 0;
}