#include "queue.h"

Queue::Queue() {
	this->top = -1;
}

void Queue::push(int index) {
	if (top < QUEUE_SIZE - 1 && index > -1) {
		for (int i = top; i > -1; i--) {
			queue[i + 1] = queue[i];
		}
		queue[0] = index;
		top++;
	}
}

void Queue::pop() {
	if (!isEmpty()) {
		for (int i = 0; i <= top; i++) {
			queue[i] = queue[i + 1];
		}
		top--;
	}
}

int Queue::peek() {
	int index;
	if (!isEmpty()) {
		index = queue[0];
	}
	else {
		index = -1;
	}
	return index;
}

bool Queue::isEmpty() {
	return (top < 0);
}