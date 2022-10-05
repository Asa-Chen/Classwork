//Queues FIFO - First in first out
//stacks & queues don't have iterators

template<class T>
class QUEUE{
    public:
    QUEUE(){front = back = NULL}
    //big 3, similar to lingly linked list with tail
    void push(const T& item)
    void pop();
    T front() const {return front -> data();}
    bool empty() const {return front == NULL;}
    private:
    node<T>* front;//head
    node<T>* back;//tail

};

-------
template<class T>
void QUEUE<T>::push(const T& item) {
    if (front == NULL) {
        front = back = new node<T>(item);
    } else {
        back -> set_next(new node<T>(item));
    }

}

template<class T>
void QUEUE<T>::pop() {
    node<T>* rmptr = front;
    if (front != NULL) {
        front = front -> next();
        delete rmptr;
    }
    //special case, if you remove the last node in the list, reset the back pointer
    if (front == NULL) {
        back = NULL;
    }
}