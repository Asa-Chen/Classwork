#include <iostream>
#include <string>

// macro guards - keeps from including the header file twice
#ifndef BANK_H
#define BANK_H

namespace chen{
class Bankacct{
    public:
    // Constructor
    Bankacct(const std::string& id = "", double b = 0.0, double ir = 1.0);

    // Accessors
    std::string get_id () const; // you could put the defenitions in the header file if they are short. I.e {return owner_id}
    double get_balance () const;
    double get_interest () const;

    //Mutators 
    //void set_ownerid (std::string id);

    //Input / Output
    void input (std::istream& ins);
    void output (std::ostream& outs) const; // Output is const because it shouldn't change data

    //Operators as friends
    //friend keyword allows the function to change data even in public 
    //friend Bankacct operator + (const Bankacct& b1, const Bankacct& b2) const; //const marks the whole function as const
    //friend Bankacct operator * (const Bankacct& b1, double amt);

    //Operators as members
    Bankacct operator + (const Bankacct & b2) const;//When operators are members, the operator is a memeber of the object on the left. I.e. mine + ours; + automatically uses "mine"
    Bankacct operator * (double amt) const;
    bool operator < (const Bankacct & b2) const;//need to pass in the right side object you want to compare to the left


    private:
    std::string ownerid;
    double balance;
    double interest_r;

};
std::istream& operator >> (std::istream& ins, Bankacct& b); // for operators that are no class members, you need to pass in both left and right objects
//returning a stream instead of void in order to "stack". I.e. cout << "hello" << "world"; 
//You must return an istream in order to stack inputs, if not, void will end the line early

std::ostream& operator >> (std::ostream& outs, const Bankacct& b);

}


#endif