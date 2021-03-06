#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BENCH
#define IF_ENABLED

#ifndef BENCH
	#define N 10
#endif

int main(void)
{
	/*
		MAPPING : 
		- a[i] is the number i
		- a[i] = 1 means that i is a prime
		- a[i] = 0 means that i is not a prime
	 */
#ifdef BENCH
	FILE* output = fopen("out.csv", "w");
	for (int N = 1000000; N <= 50000000; N += 1000000)
#endif
	{
		int* a = malloc(N * sizeof(int));
		if (a == NULL)
			abort();

		//Initialization
		for (int i = 2; i < N; i++)
			a[i] = 1;

#ifdef BENCH
		clock_t begin = clock();
#endif

		for (int i = 2; i < N; i++)
		{
#ifdef IF_ENABLED
			if (a[i]) //if i is a prime
#endif
			{
				for (int j = i; j < N/i; j++) //for every multiple of it in our number range
					a[i * j] = 0; //mark it as non-prime
			}
		}

#ifdef BENCH
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		fprintf(output, "%d,%f\n",N ,time_spent);
		free(a);
		printf("Completed for N= %d\n", N);
#else
		for (int i = 2; i < N; i++)
		{
			if (a[i])
				printf("%9d ", i);
		}
		puts("");
#endif
	}
#ifdef BENCH
	fclose(output);
#endif
}