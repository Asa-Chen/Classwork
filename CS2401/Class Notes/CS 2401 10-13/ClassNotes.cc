//template functions


//non-meber template functions (i.e. not part of a class/struct)
void swap(int& n,int& m) {
    int tmp;
    tmp = n;
    n = m;
    m = tmp;
}  //pass swap by ref. so that the values can be changed

void swap(double& x, double& y) {
    double tmp;
    tmp = x;
    x = y; 
    y = tmp;
}

void swap(string& a, string& b){
    string tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swap(Check& c1, Check& c2){
    Check tmp;
    tmp = c1;
    c1 = c2;
    c2 = tmp;

}
//Its annoying to write a bunch of functions for all these data types
//template solves that problem


//"T" is the template parameter, used to as a name placeholder for the data type we want to use(Which is any)
template<class T>
void swap(T& thing1, T& thing2){
    T tmp;
    tmp = thing1;
    thing1 = thing2;
    thing2 = tmp;
}//The problem with this, is that it won't compile. BECAUSE, it doesn't give a data type anywhere.
//Don't put this in a cc file because it wont compile. Needs to be in a header file, i.e. "myswap.h"



//main file

#include "myswap.h"
#include "check.h"
using namespace std;
int main {
    int n,m;
    double x,y;
    Check c1,c2;

    //read some data into the variables

    //instantiation - calling the function with different types of data
    swap (n,m); //instantiating with integers
    swap (x,y); //instantiating with doubles
    swap (c1,c2); //instantiationg with checks
}

//templates work well for saving programming time, not compiling time


template<class T,class S>//template functions can deal with multiple types of data
void ssort(T a[], S used){
    int smallsp;
    for (int i = 0; i < used - 1; i++){
        smallsp = 1;
        for (int j = i + 1; j < used; j++) {
            if (a[j] < a[smallsp]) {
                smallsp = j;
            }
        }
        swap(a[j], a[smallsp]); //instantiation can be in other functions besides main
    }
}


int main() {
    MyFriend friends[100];
    int used;
    ssort(friends, used);
}

//unable to instantiate error = most likely missing an overloaded operator to compare data


//you can make an entire class a template
template<class T> //.h file
class Tcont{ //cont for container
    public:
    static const int SIZE = 200;
    Tcont();
    void add(const T& item); //you can use const T& if the item is very large
    void display()const;
    private:
    T data[SIZE];
    int used;
};


