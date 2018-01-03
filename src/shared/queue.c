#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Queue_ {
	int front,rear,size;
	int capacity;
	int *array;
};

Queue * queue_init(int capacity) {
	Queue * q = (Queue *) malloc(sizeof(Queue));
	q -> front = q -> size = 0;
	q -> rear = capacity - 1;
	q -> array = (int *) malloc(sizeof(int) * capacity);
	return q;
}
void queue_enqueue(Queue *q, int value) {
	if(queue_isfull(q))
		return;
	q -> rear = q -> rear + 1;
	q -> size = q -> size + 1;
	q -> array[q -> rear] = value;
}
void queue_dequeue(Queue *q, int value) {
	
}
bool queue_isempty(Queue *q) {
	return q -> size == 0;
}
bool queue_isfull(Queue *q) {
	return q -> size == q -> capacity;
}