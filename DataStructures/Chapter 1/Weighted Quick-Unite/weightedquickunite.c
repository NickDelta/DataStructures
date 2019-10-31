#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

int root(int id[] , int i)
{
	while (i != id[i])
	{
		id[i] = id[id[i]]; //Path compression
		i = id[i]; 
	}
	return i;
}

bool find(int id[] ,int p, int q) 
{ 
	return root(id,p) == root(id,q); 
}

void unite(int id[],int sz[],int p, int q) 
{ 
	int i = root(id,p);
	int j = root(id,q);

	if (sz[i] < sz[j])
	{
		id[i] = j;
		sz[i] += sz[j];
	}
	else
	{
		id[j] = i;
		sz[j] += sz[i];
	}
}

int main(void)
{
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("out.txt", "w");

	fprintf(output, "p\tq\t");
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < N; i++)
			fprintf(output, "%d\t", i);
		fprintf(output, "|\t");
	}
	fprintf(output, "\n\n");

	int p, q;

	int id[N];
	int sz[N];

	for (int i = 0; i < N; i++) 
	{ 
		id[i] = i; 
		sz[i] = 1;
	}

	while (fscanf(input, "%d%d", &p, &q) == 2)
	{

		if (find(id, p, q) == false)
		{
			unite(id,sz, p, q);
			printf("%d-%d\n", p, q);
		}
			

		fprintf(output, "%d\t%d\t", p, q);
		for (int i = 0; i < N; i++)
		{
			fprintf(output, "%d\t", id[i]);
		}
		fprintf(output, "|\t");

		for (int i = 0; i < N; i++)
		{
			fprintf(output, "%d\t", sz[i]);
		}
		fprintf(output, "|\n");

	}
	fclose(input);
	fclose(output);

}