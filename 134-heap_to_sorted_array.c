#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array-integer.
 *
 * @heap: A pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: Sorted in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t heap_size;
	int *list;
	int extract_num, i = 0;

	if (!heap)
		return (NULL);
	heap_size = binary_tree_size(heap);
	*size = heap_size;
	list = malloc(heap_size * sizeof(int));
	if (!list)
		return (NULL);
	while (heap)
	{
		extract_num = heap_extract(&heap);
		list[i] = extract_num;
		i++;
	}
	return (list);
}
