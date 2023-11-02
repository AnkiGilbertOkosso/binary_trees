#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: Points to the first node.
 * @second: Points to the second node.
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *put, *popp;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	put = first->parent, popp = second->parent;
	if (first == popp || !put || (!put->parent && popp))
		return (binary_trees_ancestor(first, popp));
	else if (put == second || !popp || (!popp->parent && put))
		return (binary_trees_ancestor(put, second));

	return (binary_trees_ancestor(put, popp));
}

