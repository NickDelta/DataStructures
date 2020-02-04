#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
}node;

node* initialize_node(int value , node* left_child , node* right_child)
{
	node* n = malloc(sizeof(struct node));
	n->value = value;
	n->left = left_child;
	n->right = right_child;

	return n;
}

node* create_example()
{
	node* node_9 = initialize_node(9, NULL, NULL);
	node* node_5 = initialize_node(5, NULL, NULL);

	node* node_6 = initialize_node(6, node_5, node_9);
	node* node_14 = initialize_node(14, NULL, NULL);

	node* node_13 = initialize_node(13, node_6, node_14);

	node* node_16 = initialize_node(16, NULL, NULL);
	node* node_19 = initialize_node(19, NULL, NULL);

	node* node_18 = initialize_node(18, node_16, node_19);

	node* root = initialize_node(15, node_13, node_18);

	return root;
}

void print_postOrder(node* node, int height)
{
	if (node == NULL)
		return;

	print_postOrder(node->left,height + 1);
	print_postOrder(node->right, height + 1);
	printf("Value: %d , height: %d\n", node->value, height);
}

int main()
{
	node* tree = create_example();
	traverse(tree);
}