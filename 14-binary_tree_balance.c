#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_node = 0, right_node = 0;

		left_node = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_node = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((left_node > right_node) ? left_node : right_node);
	}

	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}
