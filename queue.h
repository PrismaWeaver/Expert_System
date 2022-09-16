#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_SIZE 32

class Queue {
public:

    //constructor
    Queue();

    //functions
    void push(int);
    void pop();
    int peek();
    bool isEmpty();
    
private:

    int top; // this is your top index
    int queue[QUEUE_SIZE]; // this is your queue, it is an array of int values
};

#endif 