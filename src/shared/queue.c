#include "queue.h"
queue * queue_init(int capacity) {
	queue * q = (queue *) malloc(sizeof(queue));
	q -> front = q -> size = 0;
	q -> rear = capacity - 1;
	q -> array = (int *) malloc(sizeof(int) * capacity);
	return q;
}
void queue_enqueue(queue *q, int value) {
	if(queue_isfull(q))
		return;
	q -> rear = q -> rear + 1;
	q -> size = q -> size + 1;
	q -> array[q -> rear] = value;
}
void queue_dequeue(queue *q, int value) {
	
}
bool queue_isempty(queue *q) {
	return q -> size == 0;
}
bool queue_isfull(queue *q) {
	return q -> size == q -> capacity;
}