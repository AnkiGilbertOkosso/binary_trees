#include "binary_trees.h"

int binary_tree_is_heap(const binary_tree_t *tree);
int parent_check(const binary_tree_t *tree);
int is_binary_tree_complete(const binary_tree_t *tree);
int is_tree_complete(const binary_tree_t *tree, int i, int c_nodes);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 *
 * @tree: Points to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!is_binary_tree_complete(tree))
		return (0);

	return (parent_check(tree->left) && parent_check(tree->right));
}

/**
 * parent_check - Checks if parent has a greater value than its childs.
 *
 * @tree: Points to the node.
 *
 * Return: 1 if parent has a greater value, 0 otherwise
 */
int parent_check(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (parent_check(tree->left) && parent_check(tree->right));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Tree root.
 * Return: Size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * is_binary_tree_complete - Calls to is_tree_complete function.
 *
 * @tree: Tree root.
 * Return: 1 if tree is complete, 0 otherwise
 */
int is_binary_tree_complete(const binary_tree_t *tree)
{
	size_t c_nodes;

	if (tree == NULL)
		return (0);

	c_nodes = binary_tree_size(tree);

	return (is_tree_complete(tree, 0, c_nodes));
}

/**
 * is_tree_complete - Checks if tree is complete.
 *
 * @tree: Pointer to the tree root.
 * @i: Node index.
 * @c_nodes: Number of nodes.
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int is_tree_complete(const binary_tree_t *tree, int i, int c_nodes)
{
	if (tree == NULL)
		return (1);

	if (i >= c_nodes)
		return (0);

	return (is_tree_complete(tree->left, (2 * i) + 1, c_nodes) &&
		is_tree_complete(tree->right, (2 * i) + 2, c_nodes));
}
