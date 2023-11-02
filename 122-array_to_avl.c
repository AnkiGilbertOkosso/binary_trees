#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 *
 * @array: Points to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: Points to the root node of the created AVL tree, NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
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
			if (avl_insert(&tree, array[ind]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
