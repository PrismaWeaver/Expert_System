#ifndef STACK_H
#define STACK_H
#define STACK_SIZE 32

class Stack {
public:

    //constructor
    Stack();

    //functions
    void push(int);
    void pop();
    int peek();
    bool isEmpty();
    
private:

    int top; // this is your top index
    int stack[STACK_SIZE]; // this is your stack, it is an array of int values
};

#endif