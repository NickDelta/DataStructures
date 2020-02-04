#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

void print_postOrder(node* node, int height)
{
	if (node == NULL)
		return;

	print_postOrder(node->left, height + 1);
	print_postOrder(node->right, height + 1);
	printf("Value: %d , height: %d\n", node->data, height);
}

node* create_balanced_tree(int* sorted_array, int array_size)
{
	if (array_size <= 0)
		return NULL;

	node* n = malloc(sizeof(struct node));
	
	float median = array_size / 2;

	n->data = sorted_array[(int)floor(median)];
	n->left = create_balanced_tree(sorted_array,(int)floor(median));
	n->right = create_balanced_tree(&sorted_array[(int)floor(median) + 1], array_size - (int)floor(median) - 1);

	return n;
}

int main()
{
	int arr[] = { 5,6,9,13,14,15,16,18,19};

	node* tree = create_balanced_tree(arr, 9);
	print_postOrder(tree,0);
}