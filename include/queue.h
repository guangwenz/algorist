#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct
{
	int front,rear,size;
	int capacity;
	int *array;
} queue ;

queue * queue_init(int capacity);
void queue_enqueue(queue *q, int value);
void queue_dequeue(queue *q, int value);
bool queue_isempty(queue *q);
bool queue_isfull(queue *q);
#endif