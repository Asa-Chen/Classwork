#include "bank.h"
using namespace std;

namespace chen{


Bankacct::Bankacct(const std::string& id = "", double b = 0.0, double ir = 1.0){
    ownerid = id;
    balance = b;
    interest_r = ir;
}



    // Accessors
    string Bankacct::get_id () const{
        return ownerid;
    }
     // you could put the defenitions in the header file if they are short. I.e {return owner_id}
    double Bankacct::get_balance () const{
        return balance;
    }
    double Bankacct::get_interest () const{
        return interest_r;
    }
    //Mutators 
    //void set_ownerid (std::string id);

    //Input / Output
    void Bankacct::input (std::istream& ins){

    }
    void Bankacct::output (std::ostream& outs) const {

    } // Output is const because it shouldn't change data

    /*
    //Operators as friends
    //friends keywords allows the function to change data even in public 
    Bankacct operator + (const Bankacct& b1, const Bankacct& b2) {
        Bankacct tmp; // when implimenting friend functions, "friend" is not required
        tmp.ownerid = b1.ownerid + " " + b2.ownerid;
        tmp.balance = b1.balance + b2.balance;
        tmp.interest_r = (b1.interest_r + b2.interest_r) / 2.0;
        return tmp;
    } //const marks the whole function as const
    Bankacct operator * (const Bankacct& b1, double amt) {
        Bankacct tmp;
        tmp.ownerid = b1.ownerid + " " + b2.balance;
        tmp.balance = b1.balance + b2.balance;
        tmp.interest_r = (b1.interest_r + b2.interest_r) / 2.0;
        return tmp;

    }
    */

   Bankacct Bankacct::operator + (const Bankacct& b2) const{
       Bankacct tmp; // when implimenting friend functions, "friend" is not required
        tmp.ownerid = ownerid + " " + b2.ownerid;
        tmp.balance = balance + b2.balance;
        tmp.interest_r = (interest_r + b2.interest_r) / 2.0;
        return tmp;
   } // When operators are members, remove b1 references because that is "yourself". b1, the left hand object is included by default

   Bankacct Bankacct::operator * (double amt) const {
       Bankacct tmp;
        tmp.ownerid = ownerid + " " + b2.balance;
        tmp.balance = balance + b2.balance;
        tmp.interest_r = (interest_r + b2.interest_r) / 2.0;
        return tmp;
   }

   bool  Bankacct::operator < (const Bankacct& b2) const{
       return balance < b2.balance;
   }

   istream& operator >> (istream& ins, Bankacct& b){
       b.input(ins);
       return ins;
   }

   ostream& operator << (ostream& outs, const Bankacct& b){
       b.output(outs);
       return outs;
   }

    private:
    std::string ownerid;
    double balance;
    double interest_r;
}
//First lab is operator overloading!