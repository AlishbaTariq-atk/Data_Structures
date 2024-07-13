#include <iostream> 

using namespace std;

class queue
{
    string *arr;
    int length;
    int capacity;
    int front;
    int rear;

    public:
        queue(int capacity)
        {
            this->capacity = capacity;
            length = 0;
            arr = new string [capacity];
            front = 0;
            rear = -1;
        }
        ~queue()
        {
            delete[] arr;
        }
        bool isFull()
        {
            if(length == capacity)
            {
                return true;
            }
            else
                return false;
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
            if(isFull())
            {
                cout << "Queue Overflow!" << endl;
                return;
            }
            if(rear == capacity-1)
            {
                rear = 0;
            }
            else
            {
                rear ++;
            }    
                arr[rear] = value;
                cout << "   Patient " << value << "  now on waiting list.\n" << endl;
                length ++;
            
        }
        void dequeue()
        {
            if(isEmpty())
            {
                cout << "Queue Underflow!" << endl;
                return;
            }
            //string value = arr[front];
            if(front == capacity-1)
            {
                cout << "Patient: " << arr[front] << " now with the doctor\n" << endl; 
                front = 0;
                length --;
                
            }
            else
            {
                cout << "Patient: " << arr[front] << " now with the doctor\n" << endl; 
                front ++;
                length --;
                return ;
            }
        }
        void next_patient()
        {
            if(isEmpty())
            {
                cout << "No next patient on the list!" << endl;
                return ;
            }
            else
            {
                cout << "Next patient: " << arr[front] << endl;
                return;
            }
            
        }
        void display()
        {
            if(isEmpty())
            {
                cout << "No  curret patients!" << endl;
                return;
            }
            int index = front;
            for(int i = 0; i < length; i++)
            {
                cout << "\nPatient " << i+1 << ": " << arr[index] << endl;
                if(index == capacity-1)
                {
                    index = 0;
                }
                else 
                {
                    index ++;
                }
            }
            cout << endl;
            return;
        }

};

int main()
{
    int size;
    int option;

    cout << "Enter the number of seats in waiting area: ";
    cin >> size;
    queue patients(size);

    while(option != 5)
    {
        cout << "Enter an option:\n"
             << " 1. Enter a paitent in waiting list\n"
             << " 2. Send next patient to doctor\n"
             << " 3. View next patient\n"
             << " 4. View all Patients on waiting list\n"
             << " 5. Exit" << endl
             << "   Option: ";
        cin >> option;

        switch(option)
        {
            case 1:
            {
                if(patients.isFull())
                {
                    cout << "Sorry, the waiting list is full!\n" << endl;
                    break;
                }
                string name;
                cout << "Enter patient name: " << endl;
                getline(cin>> ws, name);
                patients.enqueue(name);
                break;
            }
            case 2:
            {
                if(patients.isEmpty())
                {
                    cout << "No patient in waiting list!" << endl;
                }
                patients.dequeue();
                break;
            }
            case 3:
            {
                patients.next_patient();
                break;
            }
            case 4:
            {
                patients.display();
                break;
            }
            default:
                break;
        }     
    }



    return 0;
}