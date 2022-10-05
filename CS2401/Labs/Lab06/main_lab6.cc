/*************************************************************************
     Lab Assignment 6: This is another lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				Spring 2014
           Patricia Lindner             Fall 2021
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node{
     int data;
     node* next;
};


// These are the three I have implemented for you
void build_list(node*& head);  // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);

//These are the two that you are to write, as described in the 
//instructions page.

void remove_repeats(node*& head);
void display_repeats(node*& head); 
void split_list(const node* original, node*& lesser, node*& greater, int split_value);



int main(){
     int start, stop;
     int split;
     node* head = NULL;
     node* lesser;
     node* greater;

     start = time(NULL);
     build_list(head);
     stop = time(NULL);
     cout << "Time to build list = " << stop - start << "seconds.\n";

     start = time(NULL);
     show_list(head);
     stop = time(NULL);
     cout << "Time to print list = " << stop - start << "seconds.\n";
     cout << "Size of the list = " << size(head) << endl;

     start = time(NULL); //remove duplicates & timer
     remove_repeats(head);
     stop = time(NULL);
     cout << "\ntime to clean list = " << stop - start << "seconds.\n";

     start = time(NULL); //print new list
     show_list(head);
     stop = time(NULL);
     cout << "Time to print list = " << stop - start << "seconds.\n";
     cout << "Size of the list = " << size(head) << endl;


     cout << "\nPlease input split value: ";
     cin >> split;

     start = time(NULL); //split list & timer
     split_list(head, lesser, greater, split);
     stop = time(NULL);
     cout << "Time to split list = " << stop - start << "seconds.\n\n";

     start = time(NULL); //print greater list
     show_list(greater);
     stop = time(NULL);
     cout << "Time to print greater list = " << stop - start << "seconds.\n";
     cout << "Size of the list = " << size(greater) << endl << endl;

     start = time(NULL); //print lesser list
     show_list(lesser);
     stop = time(NULL);
     cout << "Time to print lesser list = " << stop - start << "seconds.\n";
     cout << "Size of the list = " << size(lesser) << endl;


     return 0;
}

// builds a linked list of 2000 random integers, all in the range 1 - 500
void build_list(node*& head){
     node* cursor;

     head = new node;
     head -> data = rand()%500 + 1;

     cursor = head;
     for(int i = 0; i < 2000; ++i){
	cursor -> next = new node;
        cursor = cursor -> next;
        cursor -> data = rand()%500 + 1;
     }
     cursor -> next = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
     const node* cursor = head;

     while(cursor !=  NULL){
          cout << cursor -> data << "  ";
          cursor = cursor -> next;
     }
     cout << endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor -> next;
	}
	return count;
}

void remove_repeats (node*& head) {
     node* target; 
     node* cursor;
     node* previous;
     // -- Removal Loop 1
     target = head; //set target value at beginning of list
     while (target != NULL) { //loop through the entire list
          cursor = target; //start at the given target value
          while (cursor != NULL && cursor -> next != NULL) { //runs through the remaining list infront of the target
               previous = cursor;
               cursor = cursor -> next;
               if (cursor -> data == target -> data) { //if there is a duplicate value, delete it
                    previous -> next = cursor -> next;
                    delete cursor;
               }
          }
          target = target -> next;
     }
     // -- Removal Loop 2
     target = head; //For some reason, the way I've built the function means that it has to filter the list twice to catch all the duplicates :(
     while (target != NULL) {
          cursor = target;
          while (cursor != NULL && cursor -> next != NULL) {
               previous = cursor;
               cursor = cursor -> next;
               if (cursor -> data == target -> data) {
                    previous -> next = cursor -> next;
                    delete cursor;
               }
          }
          target = target -> next;
     }

}


void split_list(const node* original, node*& lesser, node*& greater, int split_value) {
     lesser = NULL;
     greater = NULL;
     while (original != NULL) {
          if (original -> data == split_value) {
          //do nothing
          } else if (original -> data < split_value) {
               if (lesser == NULL) {
                    lesser = new node;
                    lesser -> data = original -> data;
                    lesser -> next = NULL;
               } else {
                    node* tmp = lesser;
                    while(tmp -> next != NULL) {
                         tmp = tmp -> next;
                    }
                    tmp -> next = new node;
                    tmp = tmp -> next;
                    tmp -> next = NULL;
                    tmp -> data = original -> data;
               }
          } else if (original -> data > split_value) {
               if (greater == NULL) {
                    greater = new node;
                    greater -> data = original -> data;
                    greater -> next = NULL;
               } else {
                    node* tmp = greater;
                    while (tmp -> next != NULL) {
                         tmp = tmp -> next;
                    }
                    tmp -> next = new node;
                    tmp = tmp -> next;
                    tmp -> next = NULL;
                     tmp -> data = original -> data;
               }

          }
          original = original -> next;
     }

}
