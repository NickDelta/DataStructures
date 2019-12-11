#include <stdio.h>
#include <stdlib.h>

typedef struct _Item
{
	int size;
	int val;
}Item;

#define ARRSIZE 3
Item items[ARRSIZE];

/*Multiple options
  1. N size array (bad implementation memory-wise)
  2. Linked list with size as primary key (slow cause of searching operations and mallocs)
  3. GCD Addressing (We can benefit big-time if GCD is large and we keep random access)
  4. Hybrid approach of 2 and 3
  5. Using a Dictionary (Probably the best solution)
  5. Something else ??
  */


#define UNKNOWN -1
int maxknap[100];

int knap(int cap)
{
	int space;
	int max = 0;

	if (maxknap[cap] != UNKNOWN)
		return maxknap[cap];

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
	maxknap[cap] = max;
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

	for (int i = 0; i < 100; i++)
	{
		maxknap[i] = UNKNOWN;
	}

	printf("%d", knap(99));

}