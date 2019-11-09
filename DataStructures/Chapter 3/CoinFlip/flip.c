#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heads()
{
	return rand() < RAND_MAX / 2;
}

int main(int argc , char *argv[])
{
	srand(time(NULL));

	int N = atoi(argv[1]);
	int M = atoi(argv[2]);

	int* f = malloc((N + 1) * sizeof(int));

	for (int i = 0; i <= N; i++)
		f[i] = 0;

	int j;
	for (int i = 0; i < M; i++)
	{
		int cnt = 0;

		for ( j = 0; j <= N; j++)
			if (heads())
				cnt++;

		f[cnt]++;
	}

	for (int i = 0; i <= N; i++)
	{
		printf("%2d", i);
		for (int j = 0; j < f[i]; j += 10)		
			printf("*");

		printf("\n");
	}
}