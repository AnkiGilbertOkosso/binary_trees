#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: A pointer to the root node of the tree to count the number of leaves.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leave_count = 0;

	if (tree)
	{
		leave_count += (!tree->left && !tree->right) ? 1 : 0;
		leave_count += binary_tree_leaves(tree->left);
		leave_count += binary_tree_leaves(tree->right);
	}

	return (leave_count);
}
