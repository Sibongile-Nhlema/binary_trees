#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes
 * with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes with one chile or null
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		counter ++;

	counter += binary_tree_nodes(tree->left);
	counter += binary_tree_nodes(tree->right);

	return (counter);
}
