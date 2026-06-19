#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int stack1[100];
	int stack2[100];
	ssize_t sp1;
	ssize_t sp2;
} MyQueue;

MyQueue *myQueueCreate() {
	MyQueue *obj = malloc(sizeof(MyQueue));
	obj->sp1 = -1;
	obj->sp2 = -1;
	return obj;
}

void myQueuePush(MyQueue *obj, int x) {
	obj->stack1[++obj->sp1] = x;
}

int myQueuePop(MyQueue *obj) {
	if (obj->sp2 == -1) {
		while (obj->sp1 != -1) {
			obj->stack2[++obj->sp2] = obj->stack1[obj->sp1--];
		}
	}
	if (obj->sp2 == -1) abort();
	int element = obj->stack2[obj->sp2--];
	return element;
}

int myQueuePeek(MyQueue *obj) {
	if (obj->sp2 == -1) {
		while (obj->sp1 != -1) {
			obj->stack2[++obj->sp2] = obj->stack1[obj->sp1--];
		}
	}
	if (obj->sp2 == -1) abort();
	int element = obj->stack2[obj->sp2];
	return element;
}

bool myQueueEmpty(MyQueue *obj) {
	if (obj->sp2 == -1) {
		while (obj->sp1 != -1) {
			obj->stack2[++obj->sp2] = obj->stack1[obj->sp1--];
		}
	}
	if (obj->sp2 == -1) return true;
	return false;
}

void myQueueFree(MyQueue *obj) {
	free(obj);
}
