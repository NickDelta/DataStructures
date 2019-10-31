#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

int root(int id[] , int i)
{
	while (i != id[i])
	{
		i = id[i]; 
	}
	return i;
}

bool find(int id[] ,int p, int q) 
{ 
	return root(id,p) == root(id,q); 
}

void unite(int id[],int p, int q) 
{ 
	int i = root(id,p);
	int j = root(id,q);
	id[i] = j; 
}

int main(void)
{
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("out.txt", "w");

	fprintf(output, "p\tq\t");
	for (int i = 0; i < N; i++)
		fprintf(output, "%d\t", i);
	fprintf(output, "\n\n");

	int p, q;

	int id[N];

	for (int i = 0; i < N; i++) { id[i] = i; } //Filling the id array

	while (fscanf(input, "%d%d", &p, &q) == 2)
	{

		if (find(id, p, q) == false)
		{
			unite(id, p, q);
			printf("%d-%d\n", p, q);
		}
			

		fprintf(output, "%d\t%d\t", p, q);
		for (int i = 0; i < N; i++)
		{
			fprintf(output, "%d\t", id[i]);
		}
		fprintf(output, "\n");
	}
	fclose(input);
	fclose(output);

}