#pragma once
#include <stdbool.h>
#include "Item.h"

typedef struct Queue* queue;

struct Queue
{
	Item* arr;
	int size;
	int maxSize;
	int front;
	int rear;
};

queue queue_init(int);
void queue_enque(queue, Item);
Item queue_deque(queue);
int queue_count(queue);
bool queue_isFull(queue);
bool queue_isEmpty(queue);