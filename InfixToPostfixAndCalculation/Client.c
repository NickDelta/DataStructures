#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

int main(void)
{
	stack s = stack_init(10);
	queue q = queue_init(10);

	queue_enque(q, 'H');
	queue_enque(q, 'e');
	queue_enque(q, 'l');
	queue_enque(q, 'l');
	queue_enque(q, 'o');
	
	printf("IsFull: %d IsEmpty: %d Count: %d\n", queue_isFull(q), queue_isEmpty(q), queue_count(q));
	printf("%c " ,queue_deque(q));
	printf("%c ", queue_deque(q));
	printf("%c ", queue_deque(q));
	printf("%c ", queue_deque(q));
	printf("%c ", queue_deque(q));
}