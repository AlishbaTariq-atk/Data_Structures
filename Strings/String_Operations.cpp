#include <iostream>
#include <string>

using namespace std;
void palindrome(string name);
int frequency(string name);


int main()
{
   string name;
   cout << "Enter a name: \n";
   getline (cin >> ws, name);

    int option;

    cout << "Do you want to check it for \n1. Plaindrome \n2. Frequency of a character \n3. Exit: \n  " << endl;
    cin >> option;

while(1)
{
    if (option == 1)
    {
        palindrome(name);
        break;
    }
    else if (option ==2)
    {
        frequency(name);
        break;
    }
    else if (option == 3)
    {
        break;
    }
    else 
    {
        cout << "Invalid value" << endl;
    }
   
} 

    return 0;
}
void palindrome(string name)
{
    char *p_head = &name[0];
    char *p_tail = &name[name.length()-1];
    // while(*p_tail!='\0')
    // {
    //     *p_tail ++;
    // };

    int count = 0;
        while(p_tail >= p_head)
        {
           if(*p_head != *p_tail)
           {
                break;
           }
             count++;
            *p_head++;
            *p_tail--;
        }

    if(count == 0)
    {
        cout << "Not a Palindrome"<<endl;
    }
    else
    {
        cout << "It is a Plaindrome." <<endl;
    }

}
int frequency(string name)
{
    char x;
    cout << "Enter the character you want the frequency for: "<< endl;
    cin >> x;

    char *p = &name[0];
    int count=0;
    while(*p!='\0')
    {
        if(*p == x)
        {
            count ++;
        }
        *p ++;
    }
    cout << "Frequncy for '"<< x << "' = " << count << endl; 
}