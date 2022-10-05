//USE REAL DATATYPE IN <> WHEN WRITING ANYTHING THAT WOULD BE COMPILED

#include "tcont.h"
using namespace std;

int main(){
    Tcont<int> nums; //put the data type you want to use for the class inside the <>. This would instantiate a Tcont for integers
    Tcont<double> d;
    Tcont<string> names;
    Tcont <Check> book; //can be used for any data type you've written



    nums.add(2041); //THESE FUNCTIONS ARENT CONSIDERED INSTANTIATION! 
                    //THE INSTANTIATION OF A CLASS IS IN THE CLASS DECLARATION! ^^^^^^^^^^^^
    d.add(3.14);
    names.add("John");

    nums.display();
    d.display();


}