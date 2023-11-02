#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_recursive_remove(bst_t *root, bst_t *node, int value);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *inorder_successor(bst_t *root);

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 *
 * @root: Points to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree
 *
 * Return: Points to the new root node of the tree after removing.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_recursive_remove(root, root, value));
}

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: Points to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: Points to the root node of the BST.
 * @node: Points to the node to delete from the BST.
 *
 * Return: Points to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_recursive_remove - Removes a node from a binary search tree recursively.
 * @root: Points to the root node of the BST to remove a node from.
 * @node: Points to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: Points to the root node after deletion.
 */
bst_t *bst_recursive_remove(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_recursive_remove(root, node->left, value));
		return (bst_recursive_remove(root, node->right, value));
	}
	return (NULL);
}
