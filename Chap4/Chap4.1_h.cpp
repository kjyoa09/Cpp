#include <iostream>

using namespace std;

class Date{
    private:
        int year_;
        int month_;
        int day_;

    public:
        void SetDate(int year, int month, int date);
        void AddYear(int inc);
        void Addmonth(int inc);
        void Addday(int inc);
        void ShowDate();
        
        int getCurrentMonthToalDays(int year, int month);

    // 생성자 (constructor)
    Date(int year, int month, int day){
        year_ = year;
        month_ = month;
        day_ = day;
    } 

};

void Date::SetDate(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::getCurrentMonthToalDays(int year, int month){
    static int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month != 2){return month_day[month-1];}
    else if (year % 4 == 0 && year % 100 != 0){return 29;}
    else{return 28;}
}

void Date::Addday(int inc){
    while (true)
    {int current_month_total_days = getCurrentMonthToalDays(year_,month_);

    if(day_ + inc <= current_month_total_days){day_+= inc; return;}
    else{inc-= (current_month_total_days-day_ + 1);Addmonth(1);}
    }
}

void Date::Addmonth(int inc){
    AddYear((inc+ month_ - 1)/12);
    month_ += inc % 12;
    month_ = (month_ == 12 ? 12 : month_%12);
}

void Date::AddYear(int inc){
    year_ += inc;
}