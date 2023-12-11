#include "date.h"

Date::Date(){
    day = 0;
    month = 0;
    year = 0;
    hour = 0;
    minute = 0;
}
Date::Date (int d, int m, int y){
    day = d;
    month = m;
    year = y;
    hour = 0;
    minute = 0;
}
Date::Date (int d, int m, int y, int h, int min){
    day = d;
    month = m;
    year = y;
    hour = h;
    minute = min;
}

void Date::setDate (int d, int m, int y){
    day = d;
    month = m;
    year = y;

}
void Date::setTime (int h, int min){
    hour = h;
    minute = min;

}
void Date::setDateTime(int d, int m, int y, int h, int min){
    day = d;
    month = m;
    year = y;
    hour = h;
    minute = min;

}
int Date::getDay(){
    return day;
}
int Date::getMonth(){
    return month;
}
int Date::getYear(){
    return year;
}
int Date::getHour(){
    return hour;
}
int Date::getMinute(){
    return minute;
}
ostream& operator<< (ostream& os, const Date& d){
    Date date = d;
    os << date.getDay();
    os<<"/";
    os<<date.getMonth();
    os<<"/";
    os<<date.getYear();
    os<<" ";
    if(date.getHour()!= 0){
        os<<date.getHour();
        os<<"h";
        os<<date.getMinute();
    }
    os<<endl;

    return os;
}
