#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;

struct node
{
	int item;
	link next;
};

int main(int argc, char* argv[])
{
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);

	link t = malloc(sizeof(struct node));
	if (t == NULL)
		exit(-1);

	link x = t;

	t->item = 1;
	t->next = t;

	for (int i = 2; i <= N; i++)
	{
		x->next = malloc(sizeof(struct node));
		if (x->next == NULL)
			exit(-1);

		x = x->next;
		x->next = t;

		x->item = i;
		
	}

	while (x != x->next)
	{
		for (int i = 1; i < M; i++)
			x = x->next;			
		
		N--;
		x->next = x->next->next;
	}
	printf("Lucky one is %d\n", x->item);
}
