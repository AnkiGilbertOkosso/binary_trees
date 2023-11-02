#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree);
int is_recursive_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_recursive_full(tree));
}

/**
 * is_recursive_full - Checks if a binary tree is full recursively.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is not NULL, otherwise 1.
 */
int is_recursive_full(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_recursive_full(tree->left) == 0 ||
		    is_recursive_full(tree->right) == 0)

			return (0);
	}

	return (1);
}
