#include "binary_trees.h"

int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl(const binary_tree_t *tree, int lo, int hi);
size_t height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: Points to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}

/**
 * height - Measures the height of a binary tree.
 * @tree: Points to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Points to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl(const binary_tree_t *tree, int lo, int hi)
{
	size_t low_node, high_node, dif;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		low_node = height(tree->left);
		high_node = height(tree->right);
		dif = low_node > high_node ? low_node - high_node : high_node - low_node;
		if (dif > 1)
			return (0);
		return (is_avl(tree->left, lo, tree->n - 1) &&
			is_avl(tree->right, tree->n + 1, hi));
	}
	return (1);
}

