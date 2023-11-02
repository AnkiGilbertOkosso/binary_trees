#include "binary_trees.h"

avl_t *avl_remove(avl_t *root, int value);
bst_t *bst_remove(bst_t *root, int value);
int remove_kind(bst_t *root);
int successor(bst_t *node);
void bal(avl_t **tree);

/**
 * avl_remove - Removes a node from an AVL tree.
 *
 * @root: Points to the root node of the tree for removing a node.
 * @value: The value to remove in the tree.
 *
 * Return: Points to the new root node of the tree after
 *         removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);

	return (root_a);
}

/**
 * bal - Measures balance factor of a AVL.
 *
 * @tree: Tree to go through.
 *
 * Return: Balanced factor.
 */
void bal(avl_t **tree)
{
	int balance_value;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	balance_value = binary_tree_balance((const binary_tree_t *)*tree);
	if (balance_value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * remove_kind - Function that removes a node depending of its children.
 *
 * @root: Node to remove.
 *
 * Return: 0 if it has no children or other value if it has
 */
int remove_kind(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * successor - Get the next successor i mean the min node in the right subtree.
 *
 * @node: Tree to check.
 *
 * Return: The min value of this tree.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * bst_remove - Remove a node from a BST tree.
 *
 * @root: Root of the tree.
 * @value: Node with this value to remove.
 *
 * Return: The tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int kind = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		kind = remove_kind(root);
		if (kind != 0)
			bst_remove(root->right, kind);
	}
	else
		return (NULL);
	return (root);
}
