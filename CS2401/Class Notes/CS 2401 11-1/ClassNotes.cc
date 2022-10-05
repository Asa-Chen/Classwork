//This lecture is not concerning templates or linked lists

//NEED THIS FOR LAB
//Inheritance
//"I want to take this class, and build ontop of it"

using namespace std;
class Clock{
    public:
        Clock() {hours = minutes = 0;}
        void set_time(int h, int m) {hours = h; minutes = m;}
        void advance(int amount = 1) {minutes + amount;}
        int get_hour() const {return hours;}
        int get_minutes() const {return minutes;}
        void output() const {cout << hours << ":" << setw(2) << setfill('0') << minutes;}
        bool isequal(const Clock& other) const {return hours == other.hours && minutes == other.minutes;}

    private:
        int hours;
        int minutes;

};


#include "clock.h"

int main() { //main example
    Clock time;

    time.set_time(12,4);
}


class AlarmClock:public Clock{ //:public "class name"       AlarmClock inherits all the attrubites of clock. No need to rewrite
                                //Alarm clock is a child of clock
    public:
    AlarmClock();
    void set_alarm(int ah, int am);
    bool is_ringing() {return get_hours() == alarm_h && get_minutes() == alarm_m;}
    //Clock data is private, even from classes that inherit it. So, use either Clock accessors get_hours(), or, change Clock private: to protected:
    //protected: means that the whole class family can access the data. Parents and decendance 
    bool is_ringing() {return hours == alarm_h && minutes == alarm_m;}
    void output() const {cout << "Alarm: " << alarm_h << setw(2) << setfill('0') << alarm_m << endl;}
    //If the child has its own output() defined, it will call its own then quit
    //You can manipulate the output() to call Clock as well
    //void AlarmClock::output() const {
    //    Clock::output();
        //output for alarm
    //}
    //Function overriding! - The same return type and arguments for two functions
    //Uses scope resolution and moves to closest scope first
    //Moves up the inheritance levels and runs whichever one it finds first

    bool isequal(const AlarmClock& other) const;


    private:
    int alarm_h;
    int alarm_m;

};

    bool AlarmClock::isequal(const AlarmClock& other) const {
        return Clock::isequal(other) && alarm_h == other.alarm_h && alarm_m == other.alarm_m;
    }




//Call AlarmClock is equal
wake_up.isequal(do_homework);

//call Clock is equal
time.isequal(another_time);


//A child can be passed where a parent is expected, but not the other way.
//Parent: CLock - time
//Child: AlarmClock - wake_up
// So,
time.isequal(wake_up); //This works
wake_up.isequal(time); //This wont. Tries to compare data that does not exist. //Called "slicing" 

//same as
time = wake_up; //
wake_up = time;





#include "clock.h"

int main() { //main example
    Clock time;

    time.set_time(12,4);

    AlarmClock wake_up, do_homework;
    wake_up.set_time(12,9); //Can call all clock functions
    wake_up.advance();

    //call Alarm functions
    wake_up.is_ringing();

    wake_up.isequal(do_homework);
}