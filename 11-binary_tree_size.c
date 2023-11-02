#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure its size.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s = 0;

	if (tree)
	{
		s += 1;
		s += binary_tree_size(tree->left);
		s += binary_tree_size(tree->right);
	}

	return (s);
}
