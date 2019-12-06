#pragma once
#include <stdbool.h>
#include "Item.h"

struct Stack
{
	Item* arr;
	int size;
	int top;
};

typedef struct Stack* stack;

stack stack_init(int);
void stack_push(stack, Item);
Item stack_pop(stack);
Item stack_peek(stack);
int stack_count(stack);
bool stack_isFull(stack);
bool stack_isEmpty(stack);