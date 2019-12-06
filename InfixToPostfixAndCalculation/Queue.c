#include <stdlib.h>
#include "Queue.h"

queue queue_init(int size)
{
	queue newQueue = malloc(sizeof(struct Queue));

	newQueue->arr = malloc(size * sizeof(Item));
	newQueue->size = 0;
	newQueue->maxSize = size;
	newQueue->front = 0;
	newQueue->rear = -1;
}

void queue_enque(queue q, Item item)
{
	q->rear = (q->rear + 1) % q->maxSize;
	q->arr[q->rear] = item;
	q->size++;
}

Item queue_deque(queue q)
{
	Item t = q->arr[q->front];
	q->front = (q->front + 1) % q->maxSize;
	return t;
}

int queue_count(queue q)
{
	return q->size;
}

bool queue_isFull(queue q)
{
	return q->size == q->maxSize;
}

bool queue_isEmpty(queue q)
{
	return q->size == 0;
}