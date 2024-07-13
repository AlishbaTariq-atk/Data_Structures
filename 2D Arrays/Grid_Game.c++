        #include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void display(char *p);

int main()
{
    srand(time(NULL));
    char arr[3][3];

    char *p = &arr[0][0];

    for(int i=0; i<=9 ; i++)
    {
        int random = rand() % 2;
        if(random == 0 )
        {
            *p = 'X';
        }
        else if(random == 1)
        {
            *p = '-';
        }
        p++;

    } 
    p = &arr[1][1];
    *p = 'O';
    int option;
    cout << "Choose a move, you are standing in the middle of the grid : \n1. Top\n2. Bottom\n3. Left\n4. Right" <<endl;
    cin >> option;

    switch(option)
    {
        case 1:
        {
            p = p-3;
            if (*p == '-')
            {
                cout << "Yaayy!You won ..."<<endl;
            }
            else if (*p == 'X')
            {
                cout << "You lost! It was a collision object" << endl;
            }
            p = &arr[0][0];
            display(p);
            break;
        }
        case 2:
        {
            p = p+3;
            if (*p == '-')
            {
                cout << "Yaayy!You won ..."<<endl;
            }
            else if (*p == 'X')
            {
                cout << "You lost! It was a collision object" << endl;
            }
            p = &arr[0][0];
            display(p);
            break;
        }
        case 3:
        {
            p = p-1;
            if (*p == '-')
            {
                cout << "Yaayy!You won ..."<<endl;
            }
            else if (*p == 'X')
            {
                cout << "You lost! It was a collision object" << endl;
            }
            p = &arr[0][0];
            display(p);
            break;
        }
        case 4:
        {
            p = p+1;
            if (*p == '-')
            {
                cout << "Yaayy!You won ..."<<endl;
            }
            else if (*p == 'x')
            {
                cout << "You lost! It was a collision object" << endl;
            }
            p = &arr[0][0];
            display(p);
            break;
        }
        default:
        { 
            cout << "Invalid opton!" << endl;
            break;
        }

    }
   

    return 0;
}
void display(char *p)
{
  
    for(int i=0; i<9 ; i++)
    {
        cout << *p ;
        if (i==2 || i==5 || i==8)
        {
            cout << endl;
        }
        else
        cout << "  ";
        p++;
    }
    cout << "----------------\n";
    cout << "X --> Collision Object" << endl;
    cout << "- --> Reward" << endl;
}