#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <ostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
public:
    Date();
    Date (int day, int month, int year);
    Date (int day, int month, int year, int hour, int minute);
    void setDate (int day, int month, int year);
    void setTime(int hour, int minute);
    void setDateTime(int day, int month, int year, int hour, int minute);
    int getDay();
    int getMonth();
    int getYear();
    int getHour();
    int getMinute();
    friend ostream& operator<< (ostream&, const Date&);
};


#endif // DATE_H_INCLUDED
