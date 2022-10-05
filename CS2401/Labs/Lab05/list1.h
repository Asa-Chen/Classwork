#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;

};

class Lilist{
    public:
        Lilist() {head = NULL;}
        void add(std::string item);
        void show();
        Node* search(std::string target);
        void move_front_to_back();

    private:
        Node* head;
};




void Lilist::add(std::string item){
    Node* tmp;
    if (head == NULL) {
        head = new Node;
        head -> data = item;
        head -> next = NULL;
    } else {
        for (tmp = head; tmp -> next != NULL; tmp = tmp -> next);
            //Advances the pointer to the last node in the list
        tmp -> next = new Node;
        tmp = tmp -> next;
        tmp -> data = item;
        tmp -> next = NULL;
    }
}

void Lilist::show() {
    for (Node* tmp = head; tmp != NULL; tmp = tmp -> next)
    std::cout << tmp -> data << std::endl;
}

Node* Lilist::search(std::string target) {
    for (Node* tmp = head; tmp != NULL; tmp = tmp -> next) {
        if (tmp -> data == target) {
            return tmp;
        }
    }
    return NULL;
}

void Lilist::move_front_to_back() {
    Node* tmp;
    Node* tail;
    tmp = head;
    head = head -> next;
    for (tail = head; tail -> next != NULL; tail = tail -> next);
    tail -> next = new Node;
    tail = tail -> next;
    tail -> data = tmp -> data;
    tail -> next = NULL;
}