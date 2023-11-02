#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 *
 * @tree: Points to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *piv, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	piv = tree->left;
	temp = piv->right;
	piv->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = piv;
	piv->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = piv;
		else
			temp->right = piv;
	}

	return (piv);
}
