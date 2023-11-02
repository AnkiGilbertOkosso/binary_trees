#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 *
 * @array: Points to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: Points to the root node of the created one, NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int ind;
	heap_t *base = NULL;

	for (ind = 0; ind < size; ind++)
		heap_insert(&base, array[ind]);

	return (base);
}
