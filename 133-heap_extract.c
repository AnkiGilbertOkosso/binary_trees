#include "binary_trees.h"

int heap_extract(heap_t **root);
void recurse_extract(heap_t *tree);
heap_t *max(heap_t *tree);
/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 *
 * @root: A double pointer to the root node of heap.
 *
 * Return: The node_value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	int node_value;

	if (!*root)
		return (0);
	node_value = (*root)->n;
	if (!(*root)->left)
	{
		node_value = (*root)->n;
		free(*root);
		*root = NULL;
		return (node_value);
	}
	recurse_extract(*root);
	return (node_value);
}

/**
 * max - Finds the maximum node in a tree.
 *
 * @tree: Points to the root of the tree.
 *
 * Return: The node with the maximum node_value.
 */
heap_t *max(heap_t *tree)
{
	heap_t *curr_max, *left_max, *right_max;

	if (!tree->left)
		return (tree);
	left_max = max(tree->left);
	if (left_max->n > tree->n)
		curr_max = left_max;
	else
		curr_max = tree;
	if (tree->right)
	{
		right_max = max(tree->right);
		if (right_max->n > curr_max->n)
			curr_max = right_max;
		else
			curr_max = tree;
	}
	return (curr_max);
}

/**
 * recurse_extract - Recursively extracts the max from the tree.
 *
 * @tree: Points to the root of the tree.
 */
void recurse_extract(heap_t *tree)
{
	heap_t *left_max, *right_max = NULL;

	if (!tree->left)
		return;
	left_max = max((tree)->left);
	if (tree->right)
		right_max = max(tree->right);
	if (right_max && right_max->n > left_max->n)
		left_max = right_max;
	tree->n = left_max->n;
	if (!left_max->left)
	{
		if (left_max->parent && left_max->parent->left == left_max)
			left_max->parent->left = NULL;
		if (left_max->parent && left_max->parent->right == left_max)
			left_max->parent->right = NULL;
		free(left_max);
	}
	else
		recurse_extract(left_max);
}
