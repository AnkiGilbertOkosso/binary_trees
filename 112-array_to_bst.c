#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 *
 * @array: Points to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t ind, point;

	if (array == NULL)
		return (NULL);

	for (ind = 0; ind < size; ind++)
	{
		for (point = 0; point < ind; point++)
		{
			if (array[point] == array[ind])
				break;
		}
		if (point == ind)
		{
			if (bst_insert(&tree, array[ind]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
