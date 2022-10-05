#include <list>

template <class T>
class Stack:public list<T> {
    public:
    void push(T item) {push_front(item);}
    void pop() {pop_front();}
    T top() const {return *begin();}
    bool empty() const {return size() == 0;}
    private:
    //really don't need anything since you inherited everything from the linked list 
};



int main() {
    Stack<int> nums;
    int n;
    nums.push(1);
    nums.push(2);
    n = nums.top();
    nums.pop();

    if (!nums.empty()) {
        n = nums.top();
        nums.pop();
    }

    //This is not a good thing
    nums.push_back(4); //This corrupts the stack by adding to the end of the stack
}

//You can fix that by changing public to private
template <class T>
class Stack:private list<T> { <-------//this. You can only access the publicly declared functions for the stack. Called private inheritance.
    public: