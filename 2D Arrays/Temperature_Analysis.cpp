#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void populate(int *p ,int  weeks ,int days_in_week);
void display(int *p,int  weeks ,int days_in_week);
void hottest_day(int *p, int  weeks ,int days_in_week);


int main()
{
    const int weeks = 4;
    const int days_in_week =7;
    int weekly_temp [weeks][days_in_week];
    int *p = &weekly_temp[0][0];

    populate(p ,weeks ,days_in_week);
    display(p, weeks , days_in_week);
    hottest_day(p,weeks, days_in_week);



    return 0;
}

void populate(int *p,int  weeks ,int days_in_week)
{
    srand(time(NULL));
    for (int i=0; i<weeks; i++)
    {
        for(int j=0; j<days_in_week ; j++)
        {
            
            *p = rand()% 21 + 10;
             p++;
        }
         
    }


}
void display(int *p, int weeks, int days_in_week)
{
    for(int i=0; i< weeks; i++)
    {
        cout << "WEEK " << i+1 << "   ";
        for(int j=0; j< days_in_week; j++)
        {
            cout << "Day" << j+1 << "=" << *p << "  ";
            p++;
        }
        cout << endl;
    }

}
void hottest_day(int *p, int weeks, int days_in_week)
{
    int hottest =0;
    int day=0;
    for (int i=0; i<weeks; i++)
    {
        for(int j=0; j<days_in_week; j++)
        {
            if(*p > hottest)
            {
                hottest = *p;
                day = j+1;
               
            }
            p++;
        }
        cout << "Hottest day in week " << i+1 << "= " << day <<endl;
        cout << "Temperature on that day = " << hottest << endl;
        cout << endl;
    }
}