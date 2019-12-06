#include <stdlib.h>
#include "Stack.h"

stack stack_init(int size)
{
	stack newStack = malloc(sizeof(struct Stack));

	newStack->arr = malloc(size * sizeof(Item));
	newStack->size = size;
	newStack->top = -1;

	return newStack;
}

void stack_push(stack s, Item item)
{
	s->arr[++(s->top)] = item;
}

Item stack_pop(stack s)
{
	return s->arr[(s->top)--];
}

Item stack_peek(stack s)
{
	return s->arr[s->top];
}

int stack_count(stack s)
{
	return s->top + 1;
}

bool stack_isFull(stack s)
{
	return stack_count(s) == s->size;
}

bool stack_isEmpty(stack s)
{
	return stack_count(s) == 0;
}
