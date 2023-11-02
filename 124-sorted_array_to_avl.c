#include "binary_trees.h"

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *_sort(avl_t *parent, int *array, int begin, int last);

/**
 * sorted_array_to_avl - Builds an AVL tree from an array.
 *
 * @array: Points to the first element of the array to be converted.
 * @size: The number of element in the array
 *
 * Return: Points to the root node of the created AVL tree, NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (_sort(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * _sort - Create the tree using the half element of the array.
 *
 * @parent: Parent of the node to create.
 * @array: Sorted array.
 * @begin: Position where the array starts.
 * @last: Position where the array ends.
 *
 * Return: Tree created.
 */
avl_t *_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux_val;
	int num = 0;

	if (begin <= last)
	{
		num = (begin + last) / 2;
		aux_val = binary_tree_node((binary_tree_t *)parent, array[num]);
		if (aux_val == NULL)
			return (NULL);
		root = (avl_t *)aux_val;
		root->left = _sort(root, array, begin, num - 1);
		root->right = _sort(root, array, num + 1, last);
		return (root);
	}
	return (NULL);
}
