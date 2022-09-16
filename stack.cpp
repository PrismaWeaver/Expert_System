#include "stack.h"

Stack::Stack() {
	this->top = -1;
}

void Stack::push(int index) {
	if (top < STACK_SIZE - 1 && index > -1) {
		stack[++top] = index;
	}
}

void Stack::pop() {
	if (!isEmpty()) {
		top--;
	}
}

int Stack::peek() {
	int indexTop;
	if (!isEmpty()) {
		indexTop = stack[top];
	}
	else {
		indexTop = -1;
	}
	return indexTop;
}

bool Stack::isEmpty() {
	return (top < 0);
}