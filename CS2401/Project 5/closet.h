/******************
 * Asa Chen - CS2401 Fall 2021-2022
 * Project 5 - closet.h
 * Header file for closet items, parent and children.
 *****************/


#include <string>
using namespace std;

class Closetitem {
    public:
    virtual void input(istream& ins) {}
    virtual void output(ostream& outs) const {}

};


//child items
class jacket:public Closetitem {
    public:
    jacket() {color =  material = "empty";}
    void input(istream& ins);
    void output(ostream& outs)const;
    private:
    string color;
    string material;

};

class frizbee:public Closetitem {
    public:
    frizbee() {color = "empty";}
    void input(istream& ins);
    void output(ostream& outs) const;
    private:
    string color;
};

class shirt:public Closetitem {
    public:
    shirt() {color = size = "empty";}
    void input(istream& ins);
    void output(ostream& outs) const;
    private:
    string color;
    string size;

};

class shoes:public Closetitem {
    public:
    shoes() {size = 0; style = color = "empty";}
    void input(istream& ins);
    void output(ostream& outs) const;
    private:
    int size;
    string style;
    string color;
};

class pants:public Closetitem {
    public:
    pants() {waist = 0; color = material = "empty";}
    void input(istream& ins);
    void output(ostream& outs) const;
    private:
    string color;
    string material;
    int waist;
};

class backpack:public Closetitem {
    public:
    backpack() {color = material = "empty";}
    void input(istream& ins);
    void output(ostream& outs) const;
    private:
    string color;
    string material;
};

