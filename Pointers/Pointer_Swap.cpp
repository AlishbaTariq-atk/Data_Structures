#include <iostream>

using namespace std;

void swap(int *ptr1,int *ptr2)
{
    int *temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;

    cout << "Nummber after swapping: \n";
    cout << "num1= " << *ptr1 << endl;
    cout << "num2= " << *ptr2 << endl;

}
int main()
{

 int num1= 5;
 int *p1 = &num1;
 int num2 = 10;
 int *p2 = &num2;

    cout << "Nummber before swapping: \n";
    cout << "num1= " << *p1 << endl;
    cout << "num2= " << *p2 << endl;


swap(p1, p2);
 

    return 0;
}
