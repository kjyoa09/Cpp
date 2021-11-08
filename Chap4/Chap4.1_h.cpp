#include <iostream>

using namespace std;

class Date{
    private:
        int year_;
        int month_;
        int date_;

    public:
        void SetDate(int year, int month, int date){
            year_ = year;
            month_ = month;
            date_ = date;
        }

        void AddYear(int inc){
            year_ += inc;
        }

        void Addmonth(int inc){
            month_ += inc;
        }

        void Addday(int inc){

        }

        void ShowDate(){
            cout << year_ << "." << month_ << "." << date_ << endl; 
        }
    
    }