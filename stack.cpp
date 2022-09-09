/*********************
Name: Twee Shackelford
Coding 03
Purpose: create and test a simple stack using pointers
**********************/
#include "stack.h"

Stack::Stack() {
	this->top = -1;
}

Stack::~Stack() {
	//deallocate pointer array
	for (int i = top; i < 0; i--) {
		delete stack[i];
	}
}

bool Stack::push(int rule) {
	bool success = false;
	//test if stack not full, rule possitive, and string not empty
	if (top < STACK_SIZE - 1 && rule > 0 && !vars.empty()) {
		int* ptr = new int;
		ptr = rule;
		//increment stack and push pointer to stack
		stack[++top] = ptr;
		success = true;
	}
	return success;
}

bool Stack::pop() {
	bool success = false;
	if (!isEmpty()) {
		//deallocate pointer and decrement top
		delete stack[top--];
		success = true;
	}
	else {
		success = false;
	}
	return success;
}

int Stack::peek() {
	int ruleTop;
	if (!isEmpty()) {
		//fill point with data from stack
		ruleTop = stack[top];
	}
	//fills passed struct with bunk data
	else {
		ruleTop = -1;
	}
	return ruleTop;
}

bool Stack::isEmpty() {
	return (top < 0);
}