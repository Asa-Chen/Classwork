


//searching and sorting in container class !!NEED THIS FOR PROJECT 1!!!
//"We have an array" " Whatever value im looking for" "And i just go through the array in order, searching for the value"

int i=0;
while (data[i] != target) {
    i++;
} //When this loop stops, i know that i = my target
//The problem for this loop is that we're not considering the size of the array or the used portion of the array
//fixed version
while (data[i] != target && i < used) { //used = portion of array that is filled
    i++;
} // Only finds one instance of the target
//Assume we're just looking to see if its in there or not
//THe problem with this is that the loop will check data[i] != target before i < used. 
//TO fix that,
while (i < used && data[i] != target) {
    i++;
}
if (i < used) {
    //I found the target
    //If the target was not found, i !< used
}

bool search (){
    int i =0;
    while (i<used && data[i] != target) {
        i++;
    }
    if (i<used) {
        //return whatever
        return true;
    }
    return false;
}

//To find where in the array the target is


int search () {
    int i=0;
    while (i<used && data[i] != target) {
        i++;
    }
    if (i < used) {
        return i;
    }
    return -1; //-1 is not valid, therefore, it would be really obvious if the search failed
}

//TO return the target
Myclass search(){
    int i=0;
    while (i<used && data[i] != target) {
        i++;
    }
    if (i<used) {
        return data[i];
    }
}



//Way selection sort works:
//Spots:  0 1 2 3 4 5
//Array : 3,7,4,2,1,5
//pick the smallest number and place it at the first spot
// 1 is smallest, switch 1 and 3
//Array : 1,7,4,2,3,5
// 2 is smallest, switch 2 and 7
//Array : 1,2,4,7,3,5
// 3 is the smallest, switch 3 and 4
//Array : 1,2,3,7,4,5
// 4 is smallest, switch 4 and 7
//Array : 1,2,3,4,7,5
// 5 is smallest, switch 5 and 7
//Array : 1,2,3,4,5,7
//Array has been sorted
//"Selection sort" is the name of the function
//has nested loops, so it CAN BE VERY SLOW WITH LARGE ARRAYS
//Selection sort
void MyContainer::s_sort(/* don't have to pass in anything because function is class member*/){
    int i,j,smallspot;
    //MyClass - whatever type each element of the data array is
    MyClass tmp; //need temp variable to do swapping. //tmp is for whatever data type the array is storing

    //outter loop keeps track of smallspot
    for (i = 0 ; i < used - 1; i++) { //used is given by the class?
        smallspot = i;
        //Inner loop finds the smallest piece of data in the remaining section of the array
        for(j = i + 1; j < used; j++){
            //check if data at this spot is smaller than smallspot
            if (data[j] < data[smallspot]) { //Important to overload < operator so that it can function no matter the data type
                smallspot = j;
            }         
        }
        //swap smallest data into positon i
        tmp = data[i];
        data[i] = data[smallspot];
        data[smallspot] = tmp;

    }
}


