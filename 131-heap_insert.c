#include "binary_trees.h"

heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * heap_insert- Inserts a value in Max Binary Heap.
 *
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Points to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_value, *flip_node;
	int size, leave_number, subs, tms, lev, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = binary_tree_size(tree);
	leave_number = size;

	for (lev = 0, subs = 1; leave_number >= subs; subs *= 2, lev++)
		leave_number -= subs;
	for (tms = 1 << (lev - 1); tms != 1; tms >>= 1)
		tree = leave_number & tms ? tree->right : tree->left;

	new_value = binary_tree_node(tree, value);
	leave_number & 1 ? (tree->right = new_value) : (tree->left = new_value);

	flip_node = new_value;
	for (; flip_node->parent && (flip_node->n > flip_node->parent->n);
			flip_node = flip_node->parent)
	{
		tmp = flip_node->n;
		flip_node->n = flip_node->parent->n;
		flip_node->parent->n = tmp;
		new_value = new_value->parent;
	}

	return (new_value);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Points to the tree to be measured.
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
