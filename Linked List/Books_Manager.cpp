#include <iostream> //double

using namespace std;

class date
{
    int day;
    int month;
    int year;

    public:
        date()
        {

        }
        void setdate(int day, int month, int year)
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }
        int get_day()
        {
            return day;
        }
        int get_month()
        {
            return month;
        }
        int get_year()
        {
            return year;
        }
        
};

class node
{
    public:
        string ISBN;
        string author;
        string title;
        string genre;
        date dop; //date of publication
        node *next;
        node *prev;
        int position;

    node(string ISBN, string  title, string author, string genre, int day, int month, int year)
    {
        this->ISBN = ISBN;
        this->title = title;
        this->author = author;
        this->genre =  genre;
        dop.setdate(day,month,year);
        next = NULL;
        prev = NULL;
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
            node * curr = NULL;
            while(head!=NULL)
            {
                curr = head;
                head = head->next;
                delete curr;
            }
        }
        int getlength()
        {
            return length;
        }
        node* getnode(int pos)
        {
            node *curr = head;
            for(int i =1 ; i<pos; i++)
            {
                curr = curr->next;
            }
            return curr;
        }
        void insert(string ISBN, string title, string author,string genre, int d, int m, int y)
        {
            node * n = new node(ISBN,title,author,genre,d,m,y);
            int pos = get_position(n);
            if(pos == 1)
            {
                n->next = head;
                if(head!=NULL)
                {
                    head->prev = n;
                }
                head = n;
            }
            else
            {
                node *curr = head;
                for(int i=1; i < pos-1; i++)
                {
                    curr = curr-> next;
                }
                n->prev = curr;
                n->next = curr->next;
                if(curr->next != NULL)
                {
                    curr->next->prev = n; 
                }
                curr->next =n;
            }
            length++;
        }
        int get_position(node* n) //returning  position for the new node to be inserted in ascending order . n = new node 
        {
           node* curr = head;
            int i;
            for (i = 1; i <= length; i++)
            {
                if (n->dop.get_year() < curr->dop.get_year() ||
                    (n->dop.get_year() == curr->dop.get_year() && n->dop.get_month() < curr->dop.get_month()) ||
                    (n->dop.get_year() == curr->dop.get_year() && n->dop.get_month() == curr->dop.get_month() && n->dop.get_day() < curr->dop.get_day()))
                {
                    break;
                }
                curr = curr->next;
            }
            return i; 
        }
        node * ISBN_search (string isbn)
        {
            if(length == 0)
            {
                cout << "Empty list!" << endl;
                return NULL;
            }

            node *curr = head;

            for(int i= 1 ; i <= length ; i++)
            {
                if(curr->ISBN == isbn)
                {
                    return curr;
                }
                curr = curr->next;
            }
            return NULL;
        }
        node* title_search (string name)
        {
            if (length == 0)
            {
                cout << "Empty list!" << endl;
                return NULL;
            }

            node* curr = head;

            for (int i = 1; i <= length; i++)
            {
                if (curr->title == name)
                {
                    return curr;
                }
                curr = curr->next;
            }
            return NULL;
        }
        void remove(string isbn)
        {
            node *n = ISBN_search(isbn);
            node *curr = head;
            int pos = 0;

            while (curr != NULL)
            {
                pos++;
                if (curr->ISBN == isbn)
                {
                    // Node with matching ISBN found, break the loop
                    break;
                }
                curr = curr->next;
            }

            if(pos < 1 || pos > length+1)
            {
                cout << "Invalid Poaition! "<< endl;
                return ;
            }
            curr = head;
            if(pos ==1)
            {
                head = head->next;
                delete curr;
                if(head!= NULL)
                {
                    head->prev = NULL;
                }
            }
            else
            {
                node *slow = NULL;
                for (int i=1; i<pos ; i++)
                {
                    slow = curr;
                    curr = curr->next;
                }
                slow->next = curr->next;
                if(curr->next!=NULL)
                {
                    curr->next->prev = slow;
                }
                delete curr;
            }
            length--;
            cout << "Deleted Successfully!" << endl;
        }
        void author_filter(string author)
        {
            node *curr = head;
            int count = 0;
            for (int i = 1; i <= length; i++)
            {
                if (curr->author == author)
                {
                    count++;
                    cout << count << ". [ " << curr->ISBN << ", " << curr->title << ", " << curr->author << ", " << curr->genre << ", " << curr->dop.get_day() << "-" << curr->dop.get_month() << "-" << curr->dop.get_year() << " ]" << endl;
                }
                curr = curr->next;
            }
            if (count == 0)
            {
                cout << "No related book with such author found!" << endl;
            }
        }
        void genre_filter(string name)
        {
            node *curr = head;
            node *n = title_search(name);
            int count = 0;
            for (int i = 1; i <= length; i++)
            {
                if (curr->title == name)
                {
                    continue;
                }
                else if (curr->genre == n->genre && count <= 3)
                {
                    count++;
                    cout << count << ". [ " << curr->ISBN << ", " << curr->title << ", " << curr->author << ", " << curr->genre << ", " << curr->dop.get_day() << "-" << curr->dop.get_month() << "-" << curr->dop.get_year() << " ]" << endl;
                }
                if (count == 3)
                {
                    return;
                }
                curr = curr->next;
            }
            if (count == 0)
            {
                cout << "No book with such genre found!" << endl;
            }
        }
        void display()
        {
            if(length == 0)
            {
                cout << "No book added yet!\n" << endl;
                return;
            }
           
                node *curr = head;
                cout << "\n[ISBN, Title, Author, Genre, Publication Date (dd-mm-yy)]" << endl;
                cout << "\nBooks:\n" ;
                for(int i=1 ; i<=length ; i++)
                {
                    cout << " " << i << ". [ " << curr->ISBN << ", " << curr->title << ", " << curr->author << ", " << curr->genre << ", " << curr->dop.get_day() << "-" << curr->dop.get_month() << "-" << curr->dop.get_year() << " ]"<< endl;
                    curr = curr->next;
                }
           cout << endl;
        }
};

int main()
{
    list l;
    int option;
    string isbn, title, author, genre ;
    int  d , m , y;
    while(option != 7)
    {
        cout << "\n---BOOK MANAGEMENT SYSTEM---" << endl;
        cout << "Menu\n 1. Add a book\n 2. Search a book\n 3. Display Books\n 4. Filter books by auhtor\n 5. Recommend related books\n 6. Delete a book\n 7. Exit" << endl;
        cin >> option;
        cin.ignore();

        switch(option)
        {
            case 1:
            {
                cout << "Enter\n ISBN: ";
                getline(cin >>ws, isbn);
                cout << " Title: ";
                getline(cin >>ws, title);
                cout << " Author: ";
                getline(cin >>ws, author);
                cout << " Genre: ";
                getline(cin >>ws, genre);
                while(1)
                {   
                    cout << " Date:\n (dd <space>  mm  <space> yy): ";
                    cin >> d >> m >> y;
                    if (d >= 1 && d <= 31 && m >= 1 && m <= 12 && y >= 0)
                    {
                        break;;
                    }
                    else
                    {
                        cout << "Kindly enter a valid date" << endl;
                    }
                }
                l.insert(isbn,title,author,genre,d,m,y);
                cout << "Inserted Successfully!" << endl;
                break;
            }
            case 2:
            {
                cout << "Search by\n 1. ISBN\n 2. Title" << endl;
                cin >> option;
                if(option == 1)
                {
                    cout << "Enter ISBN: ";
                    getline(cin >>ws, isbn);
                    node *n = l.ISBN_search(isbn) ;
                    if( n != NULL)
                    {
                        cout << " BOOK FOUND! " << endl;
                    }
                    else
                    {
                        cout << "BOOK NOT FOUND!" << endl;
                    }
                }
                else if(option == 2)
                {
                    cout << "Enter Title: ";
                    getline(cin >>ws, title);
                    node *n = l.title_search(title);
                    if( n != NULL)
                    {
                        cout << " BOOK FOUND! " << endl;
                    }
                    else
                    {
                        cout << "BOOK NOT FOUND!" << endl;
                    }
                }
                break;
            }
            case 3:
            {
                l.display();
                break;
            }
            case 4:
            {
                cout << "Enter author: ";
                getline(cin >>ws, author);
                cout << "Book with same author" << endl;
                l.author_filter(author);
                break;
            }
            case 5:
            {
                cout << "Enter Title: ";
                getline(cin >>ws, title);
                cout << "Related book: " << endl;
                l.genre_filter(title);
                break;
            }
            case 6:
            {
                cout << "Enter ISBN: ";
                getline(cin >>ws, isbn);
                l.remove(isbn);
                break;
            }
            default:
            {
                cout << "Invalid option !" << endl;
                break;
            }
        }
    }
    return 0;
}
