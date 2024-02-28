#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *base, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	base = tree->left;
	tmp = base->right;
	base->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = base;
	base->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = base;
		else
			tmp->right = base;
	}

	return (base);
}
