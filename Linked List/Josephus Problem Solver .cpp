#include <iostream>

using namespace std;

class node
{
    public:
        int data;
        node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }   
};

class list
{
    node *head;
    int length;

    public:
    list()
    {
        head = NULL;
        length = 0;
    }
    ~list()
    {
        node* curr = head;

        while(head!=NULL)
        {
            head = head->next;
            delete curr;
            curr = head;
        }
    }
    void insert(int value, int pos)
    {
        if(pos < 1 || pos > length+1)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        node *n = new node(value);
        node *curr = head;
        if( head == NULL)
        {
            head = n;
            head->next = head;
        }
        else if(pos == 1)
        {
            n->next = head;
            while( curr->next!=head)
            {
                curr = curr->next;
            }
            curr->next = n;
            head = n;
        }
        else 
        {
            for(int i=1 ; i< pos-1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }

    void remove(int pos)
    { 
        if (head==NULL)
        {
            cout<<"Empty list"<<endl;
            return;
        }

        if (pos<1 || pos>length)
        {
            cout<<"Invalid position"<<endl;
            return;
        }

        node *curr=head;

        if (pos==1)
        {
            node  *temp=head;

            while(temp->next!=head)
            {
                temp=temp->next;
            }
            
            head=head->next;
            temp->next=head;

            if(head->next==head)
            {
                head=NULL;
            }

            delete curr;
        }

       else
       {
        node *slow=NULL;

        for (int i=1;i<pos;i++)
        {
            slow=curr;
            curr=curr->next;
        }

        slow->next=curr->next;
        delete curr;
       }

       length--;
    }

    int j_problem(int n, int m)
    {
        node *slow = head;
        node * curr = head->next;
        int pos=0;
        int count =0;

        while(count < n-1) //loops ends when the last member survives
        {
            for(int i=1; i<= m; i++) //loop itterates via m positions
            {
                slow = slow->next;
                curr = curr->next;
            }
            //slow->next= curr->next;
            pos = getpos(slow->data);
            //cout<<pos<<endl;
            cout<<slow->data<<" eliminated"<<endl;
            remove(pos); //the required position is eliminated
            count++;
            slow=curr;
            curr=curr->next;
        }
        return getpos(curr->data); //pos of survivor returned
    }       

    void display()
    {
        cout << "The list is as follows: \n";
        node *curr = NULL;
        while(curr != head)
        {
            if(curr == NULL)
            {
                curr = head;
            }
            cout << curr->data << "  " ;
            curr = curr->next;
        }
        cout << endl;
    }
    int getvalue(int pos)
    {
        if(length == 0)
        {
            cout << "Empty list!" << endl;
            return 0;
        }
        if(pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position!" << endl;
            return 0;
        }
        node * curr = head;
        for(int i=1 ; i<=length ; i++)
        {
            if(i == pos)
            {
                return curr->data;
            }
            curr = curr->next;
        }
        return -1;
    }
    int getpos (int value)
    {
        if(length == 0)
        {
            cout << "Empty list!" << endl;
            return 0;
        }
        node * curr = head;

        for(int i=1 ; i<=length ; i++)
        {
            if(curr->data == value)
            {
                return i;
            }
            curr = curr->next;
        }
        return -1;
    }
};

int main()
{
    list josephous;
    int length;
    int interval;
    int member;

    cout << "What is the total number of members: ";
    cin >> length;

    cout << "Enter the members : " << endl; //inserting values to the list
    for(int i=1 ; i<= length ; i++)
    {
        cout << "Member " << i << ": " ;
         cin >> member;
        josephous.insert(member , i);
    }

    josephous.display();

    
    cout << "Enter the elimination interval: ";
    cin >> interval;

    int pos = josephous.j_problem(length, interval);
    int survivor = josephous.getvalue(pos);

    cout << "The last member survived is   " << survivor << " ,at position = " << pos << endl;





    return 0;
}