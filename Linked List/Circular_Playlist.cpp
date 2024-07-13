#include <iostream> //circular linked list

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
        node *curr = NULL;
        while (head != NULL)
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
    void add(string value, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position! " << endl;
            return;
        }

        node *n = new node(value);
        node *curr = head;
        if (head == NULL && pos == 1)
        {
            head = n;
            head->next = head;
        }
        else if (pos == 1)
        {
            n->next = head;
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = n;
            head = n;
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
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
        if (head == NULL)
        {
            cout << "The list is empty!" << endl;
            return;
        }
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position! " << endl;
            return;
        }

        node *curr = head;
        if (pos == 1)
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            if (head->next == head)
            {
                head = NULL;
            }
            delete curr;
        }
        else
        {
            node *slow = NULL;

            for (int i = 1; i < pos; i++)
            {
                slow = curr;
                curr = curr->next;
            }

            slow->next = curr->next;
            delete curr;
        }

        length--;
    }
    void search(string song)
    {
        if (length == 0)
        {
            cout << "Empty list!" << endl;
            return;
        }

        node *curr = head;

        for (int i = 1; i <= length; i++)
        {
            if (curr == head)
            {
                break;
            }
            if (curr == NULL)
            {
                curr = head;
            }
            if (curr->data == song)
            {
                cout << "The song " << curr->data << " is found in the list having position " << i << " in the favorites list." << endl;
            }
            curr = curr->next;
        }
    }
    void update(string new_song, int pos)
    {
        if (length == 0)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position!" << endl;
            return;
        }
        node *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        curr->data = new_song;
    }
    void print()
    {
        if (length == 0)
        {
            cout << "Empty list!" << endl;
            return;
        }
        node *curr = head;
        cout << "Playlist:\n"
             << endl;
        for (int i = 1; i <= length; i++)
        {
            cout << i << ". " << curr->data << endl;
            curr = curr->next;
        }
        cout << "-----------------------------" << endl;
    }
    void play()
    {
        int option;

        if (head == NULL)
        {
            cout << "Empty list!" << endl;
            return;
        }
        node *curr = head;
        while (option != 2)
        {

            print();
            cout << "\n\nPlaying:\n " << curr->data << endl;
            cout << "\n1. Play next song\n2. Stop" << endl;
            cin >> option;
            if (option == 1)
            {
                if (curr->next == head)
                {
                    curr = curr->next;
                    cout << "Playing from start : " << curr->data << endl;
                    
                }
                else
                {
                    curr = curr->next;
                    cout << "Playing:\n " << curr->data << endl;
                }
            }
        }
    }
};

int main()
{
    list playlist;
    int option;

    while (option != 7)
    {
        cout << "Menu:\n 1. Add a song\n 2. Delete a song\n 3. Update a song\n 4. Search a song\n 5. Print Playlist\n 6. Play song\n 7. Exit " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            string song;
            int pos;
            int favorite;

            cout << "Enter the song name: ";
            getline(cin >> ws, song);
            cout << "Do you want to add it as\n 1. Most Favorite\n 2. Least Favorite\n 3. Somewhere in the middle?" << endl;
            cin >> favorite;
            if (favorite == 1)
            {
                pos = 1;
                playlist.add(song, pos);
            }
            else if (favorite == 2)
            {
                pos = playlist.getlength() + 1; // Add as least favorite
                playlist.add(song, pos);
            }
            else if (favorite == 3)
            {
                cout << "Where to add it : ";
                cin >> pos;
                playlist.add(song, pos);
            }
            else
            {
                cout << "Invalid option!" << endl;
            }
            break;
        }
        case 2:
        {
            int pos;
            cout << "Enter position you want to delete: ";
            cin >> pos;
            playlist.remove(pos);
            break;
        }
        case 3:
        {
            int pos;
            string new_song;
            cout << "Enter new song name: ";
            getline(cin >> ws, new_song);
            cout << "Enter position at which you want to update: ";
            cin >> pos;
            playlist.update(new_song, pos);
            break;
        }
        case 4:
        {
            string song;
            cout << "Enter song name you want to search: ";
            getline(cin >> ws, song);
            playlist.search(song);
            break;
        }
        case 5:
        {
            playlist.print();
            break;
        }
        case 6:
        {
            playlist.play();
            break;
        }
        }
    }

    return 0;
}
