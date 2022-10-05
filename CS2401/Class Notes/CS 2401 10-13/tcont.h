
//DON"T PUT <> IN HERE

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


//For this, do the reverse. Read the class declaration and then the template implimentation
//Don't include the .h in the implimentation file, include the implimentation file in the header file
#include "tcont.temp"