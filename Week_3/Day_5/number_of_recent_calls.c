#include <stdlib.h>

typedef struct {
	int queue[10000];
	int head;
	int tail;
} RecentCounter;

RecentCounter *recentCounterCreate() {
	RecentCounter *obj = malloc(sizeof(RecentCounter));
	obj->head = -1;
	obj->tail = 0;
	return obj;
}

int recentCounterPing(RecentCounter *obj, int t) {
	int min = t - 3000;
	if (obj->head != -1) {
		while (obj->head < obj->tail && obj->queue[obj->head] < min)
			obj->head++;
	}
	obj->queue[obj->tail++] = t;
	if (obj->head == -1) obj->head++;
	return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter *obj) {
	free(obj);
}
