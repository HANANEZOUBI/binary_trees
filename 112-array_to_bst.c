#include "binary_trees.h"

/**
 * array_to_bst - to build a binary search tree from an array.
 * @array: A pointer to the 1st element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, 
 *         or NULL if failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, x;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (x = 0; x < i; x++)
		{
			if (array[x] == array[i])
				break;
		}
		if (x == i)
		{
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
