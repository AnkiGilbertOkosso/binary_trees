#include "binary_trees.h"

avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_recursive_insert(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value);
int balance(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);

/**
 * avl_insert - Inserts a value in an AVL Tree.
 *
 * @tree: A double pointer to the root node of the AVL tree.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_recursive_insert(tree, *tree, &new_node, value);
	return (new_node);
}

/**
 * balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * avl_recursive_insert - Inserts a value into an AVL tree recursively.
 *
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new_node: A double pointer to store the new_node node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new_node root after insertion, or NULL on failure.
 */
avl_t *avl_recursive_insert(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value)
{
	int b_fact;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_recursive_insert(&(*tree)->left, *tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_recursive_insert(&(*tree)->right, *tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	b_fact = balance(*tree);
	if (b_fact > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (b_fact < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (b_fact > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_fact < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}
