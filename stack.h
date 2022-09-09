/*********************
Name: Twee Shackelford
Coding 03
Purpose: create and test a simple stack using pointers
**********************/

#ifndef STACK_H
#define STACK_H
#include <string>
#define STACK_SIZE 30

class Stack {
public:

    //constructor
    Stack();

    //destructor
    ~Stack();

    //functions
    bool push(int, string);
    bool pop();
    int peek();
    bool isEmpty();
    
private:

    int top; // this is your top index
    int *stack[STACK_SIZE]; // this is your stack, it is an array of int pointers
};

#endif //STACK_H