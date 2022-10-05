// Add documentation for each function

#include <iostream>
    
#ifndef MYTIME_H
#define MYTIME_H
class MyTime
{   
  public:

    MyTime(int h = 0, int m = 0);   //Combined constructor 

    // Member functions
    void Reset(int h, int m);

    void input(std::istream& ins);            

    void output(std::ostream& outs);

    int get_hours() const{return hours;}

    int get_minutes() const{return minutes;}


    //implimented as const to protect objects 
    MyTime operator + (const MyTime& t2) const;
 
    MyTime operator - (const MyTime& t2) const;
 
    MyTime operator * (int num) const;

    MyTime operator / (int num) const;

    bool operator == (const MyTime& t2) const;

    bool operator < (const MyTime& t2) const;

    bool operator <= (const MyTime& t2) const;
   
  private:
      void simplify();
      int hours;        // hours can be > 24
      int minutes;      // 0 <= minutes <= 59
 };

std::istream& operator >>(std::istream& fin, MyTime& t);
    
std::ostream& operator <<(std::ostream& fout, MyTime& t);

#endif
