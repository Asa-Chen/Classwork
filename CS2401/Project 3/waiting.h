#ifndef WAITING_H
#define WAITING_H
#include <iostream>
#include <fstream>
#include "node.h"
#include "appointment.h"
#include "date_time.h"

class Waiting {

    public:
    //constructor
    Waiting();

    //big 3
    ~Waiting();
    Waiting(const Waiting& other);
    void operator = (const Waiting& other);

    //accessors 
    void display(std::ostream& outs) const;
    Appointment find(std::string& target) const;
    int waiting() const;
    int longest_wait() const;
    int average_wait() const;
    int oldest() const;
    int youngest() const;
    int average_age() const;

    //mutators
    void add(Appointment& ap);
    void remove(std::string& target);


    //file read-in/read-out
    void load(std::istream& ins);
    void save(std::ostream& outs) const;

    private:
    node* head;
    int aptcount;

};





#endif