#include <iostream>
#include <vector>
using namespace std;

class Patient 
{
public:
    string name;
    int urgency;

    Patient(string name, int urgency) 
    {
        this->name=name;
        this->urgency=urgency;
    }
};

class Heap {
public:
    vector<Patient> t;

    int getParent(int child) 
    {
        if(child == 0)
            return -1;
        else
            return (child -1)/2;  //  child/2 (if zero index khali)
    }

    int getLeft(int parent) 
    {
        int l = (2*parent)+1;  //2 * child
        if(l >= t.size())
        {
            return -1;
        }
        else 
        return l;
    }

    int getRight(int parent) 
    {  
       int r = (2*parent)+2;   //(2 * child) + 1
        if(r >= t.size())
        {
            return -1;
        }
        else 
        return r;
    }

    void swap(Patient *a, Patient *b) 
    {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node) 
    {
        int p = getParent(node);
        if (p != -1 && t[p].urgency > t[node].urgency)
        {
            swap(&t[p], &t[node]);
            heapifyUp(p);
        }
        
    }

   
    void heapifyDown(int node)
    {
        int min;
        int l = getLeft(node);
        int r = getRight(node);
        if ( (l!= -1 && t[node].urgency > t[l].urgency) || (r!=-1 && t[node].urgency > t[r].urgency) )
        {
            if(t[l].urgency < t[r].urgency)
            {
                min = l;
            }
            else 
            {
                min = r;
            }
            swap(&t[node], &t[min]);
            heapifyDown(min);
        }
    }


    void insert(Patient patient) 
    {
        t.push_back(patient);
        int node = t.size()-1;
        heapifyUp(node);
    }

    void del() 
    {
        swap(&t[0], &t[t.size() - 1]);
        t.pop_back();
        heapifyDown(0);
    }

    void updateUrgency(string patientName, int newUrgency) 
    {
        int index = -1;
        for (int i = 0; i < t.size(); i++) 
        {
            if (t[i].name == patientName) 
            {
                index = i;
                break;
            }
        }
        if (index != -1) 
        {
            t[index].urgency = newUrgency;
            heapifyDown(0);
            cout << "Update successful!" << endl;
        } 
        else 
        {
            cout << "No such patient found!" << endl;
        }
    }
    bool isEmpty()
    {
        if(t.empty())
        {
            return true;
        }
        else 
        return false;
    }


    void display() 
    {
        if (t.empty()) {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < t.size(); i++) {
            cout << "Name: " << t[i].name << ", Urgency: " << t[i].urgency << endl;
        }
    }
};

int main() 
{
    Heap h;
    string name;
    int urgency;
    int option;
    while(option != 5)
    {
        cout << "\nMenu:\n";
        cout << "1. Schedule Appointment\n";
        cout << "2. Send next Patient to the Doctor\n";
        cout << "3. Update Urgency\n";
        cout << "4. View Appointments\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) 
        {
            case 1: 
            {
                cout << "Enter patient's name: ";
                cin >> name;
                cout << "Enter urgency level: ";
                cin >> urgency;
                Patient p(name, urgency);
                h.insert(p);
                cout << "Appointment scheduled successfully!"<< endl;
                break;
            }
            case 2:
            {
                if(h.isEmpty())
                {
                    cout << "No patient in list" << endl;
                    break;
                }
                cout << "Sending next patient to the doctor: " << endl;
                h.del();
                h.display();
                break;
            }    
            case 3: 
            {
                if(h.isEmpty())
                {
                    cout << "No patience on list" << endl;
                    break;
                }
                int newUrgency;
                cout << "Enter patient's name for urgency update: ";
                cin >> name;
                cout << "Enter new urgency level: ";
                cin >> newUrgency;
                h.updateUrgency(name, newUrgency);
                break;
            }
            case 4:
            {
                h.display();
                break;
            }    
            case 5:
            {
                cout << "Exiting the program.\n";
                break;
            }    
            default:
                cout << "Invalid option. Please enter a valid option.\n";
                break;
        }
    } 

    return 0;
}