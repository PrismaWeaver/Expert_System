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

bool Stack::push(int rule, string vars) {
	bool success = false;
	//test if stack not full, rule possitive, and string not empty
	if (top < STACK_SIZE - 1 && rule > 0 && !vars.empty()) {
		//dynamically allocate Data struct
		Data* ptr = new Data;
		//fill struct
		ptr->rule = rule;
		ptr->vars = vars;
		//increment stack and push pointer to stack
		stack[++top] = ptr;
		success = true;
	}
	return success;
}

bool Stack::pop(Data *point) {
	bool success = false;
	if (!isEmpty()) {
		//fill point with data from stack
		point->rule = stack[top]->rule;
		point->vars = stack[top]->vars;
		//deallocate pointer and decrement top
		delete stack[top--];
		success = true;
	}
	//fills passed struct with bunk data
	else {
		point->rule = -1;
		point->vars = "";
		success = false;
	}
	return success;
}

bool Stack::peek(Data *point) {
	bool success = false;
	if (!isEmpty()) {
		//fill point with data from stack
		point = stack[top];
		success = true;
	}
	//fills passed struct with bunk data
	else {
		point->rule = -1;
		point->vars = "";
		success = false;
	}
	return success;
}

bool Stack::isEmpty() {
	return (top < 0);
}