#include <iostream>
#include <string>
using namespace std ;
class WeekDays 
{
    private:
        string Days[7] ;
        int CurrentDay ;
    public:
        WeekDays()  
        {
            Days[0] = "Sunday" ;
            Days[1] = "Monday" ;
            Days[2] = "Tuesday" ;
            Days[3] = "Wednesday" ;
            Days[4] = "Thursday" ;
            Days[5] = "Friday" ;
            Days[6] = "Saturday" ;
        }
        WeekDays(int day) 
        {
            Days[0] = "Sunday" ;
            Days[1] = "Monday" ;
            Days[2] = "Tuesday" ;
            Days[3] = "Wednesday" ;
            Days[4] = "Thursday" ;
            Days[5] = "Friday" ;
            Days[6] = "Saturday" ;
            CurrentDay = day % 7 ;
        }
        string getCurrentDay()  
        {
            return Days[CurrentDay] ;
        }
        string getNextDay() 
        {
            return Days[(CurrentDay + 1) % 7] ;
        }
        string getPreviousDay()  
        {
            return Days[(CurrentDay + 6) % 7] ;
        }
        string getNthDayFromToday(int N)
        {
            return Days[(CurrentDay + N) % 7] ;
        }
} ;
int main() 
{
    WeekDays day1 ;
    cout<<"Current Day:"<<day1.getCurrentDay()<<"\n" ;
    cout<<"Next Day:"<<day1.getNextDay()<<"\n" ;
    cout<<"Previous Day:"<<day1.getPreviousDay()<<"\n" ;
    cout<<"20 Days From Today:"<< day1.getNthDayFromToday(20)<<"\n\n" ;
    WeekDays day2(8) ;
    cout<<"Current Day:"<<day2.getCurrentDay()<<"\n" ;
    cout<<"Next Day:"<<day2.getNextDay()<< "\n" ;
    cout<<"Previous Day:"<<day2.getPreviousDay()<<"\n" ;
    cout<<"20 Days From Today:"<<day2.getNthDayFromToday(20)<<"\n" ;
    return 0 ; 
}