#include "binary_trees.h"

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is full, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*check if node has two children*/
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
	return (0);
}
