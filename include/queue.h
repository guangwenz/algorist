#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdbool.h>

struct Queue_;
typedef struct Queue_ Queue;

Queue * queue_init(int capacity);
void queue_enqueue(Queue *q, int value);
void queue_dequeue(Queue *q, int value);
bool queue_isempty(Queue *q);
bool queue_isfull(Queue *q);
#endif