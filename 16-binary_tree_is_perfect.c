#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_height_at_level(const binary_tree_t *tree, size_t level);

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is full, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, i, level_height, next_level_height;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	for (i = 0; i < height - 1; i++)
	{
		level_height = binary_tree_height_at_level(tree, i);
		next_level_height = binary_tree_height_at_level(tree, i + 1);

		if (level_height != next_level_height)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_height -  function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_height_at_level - calculate the height of the
 * binary tree at a given level
 * @tree: pointer to the root node
 * @level: the level at which the node is found
 * Return: the level or 0
 */
size_t binary_tree_height_at_level(const binary_tree_t *tree, size_t level)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	if (level == 0)
		return (1);

	left_height = binary_tree_height_at_level(tree->left, level - 1);
	right_height = binary_tree_height_at_level(tree->right, level - 1);

	return (left_height + right_height);
}

