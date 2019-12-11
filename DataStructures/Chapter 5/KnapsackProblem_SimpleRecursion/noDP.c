#include <stdio.h>
#include <stdlib.h>

typedef struct _Item
{
	int size;
	int val;
}Item;

#define ARRSIZE 3
Item items[ARRSIZE];

int knap(int cap)
{
	int space;
	int max = 0;

	for (int i = 0; i < ARRSIZE; i++)
	{
		space = cap - items[i].size;
		if (space >= 0)
		{
			int t = knap(space) + items[i].val;
			if (t > max)
				max = t;
		}
	}

	return max;
}

int main(void)
{
	items[0].size = 10;
	items[0].val = 40;

	items[1].size = 20;
	items[1].val = 100;

	items[2].size = 30;
	items[2].val = 120;

	printf("%d", knap(1));

}