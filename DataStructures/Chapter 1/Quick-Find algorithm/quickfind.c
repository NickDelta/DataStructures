#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

bool find(int id[], int p, int q) // 1 operation
{
	return id[p] == id[q];
}

void unite(int id[], int p, int q) // N operations
{
	int temp = id[p];
	for (int i = 0; i < N; i++)
	{
		if (id[i] == temp)
			id[i] = id[q];
	}
}

//Pages 31-33 
int main(void)
{
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("out.txt", "w");

	fprintf(output, "p\tq\t");
	for (int i = 0; i < N; i++)
		fprintf(output, "%d\t", i);
	fprintf(output, "\n\n");

	int p,q;

	int id[N];

	for (int i = 0; i < N; i++) { id[i] = i; } //Filling the id array


	while (fscanf(input,"%d%d", &p, &q) == 2) // M operations
	{
		if (find(id, p, q) == false) // if (id[p] == id[q]) continue; but edited to print to output
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