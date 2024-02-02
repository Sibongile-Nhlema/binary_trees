#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
				size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is full, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 * is_leaf - checks if a node is a leaf
 * @node: the node
 * Return: 1 if leaf, otherwise 0
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}

/**
 * depth - finds the depth of a tree
 * @tree: pointer to the root node
 * Return: depth or 0
 */
size_t depth(const binary_tree_t *tree)
{
	if (tree->parent != NULL)
		return (1 + depth(tree->parent));
	else
		return (0);
}

/**
 * get_leaf - finds a leaf
 * @tree: pointer to the root node
 * Return: the root node or the leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
	{
		return (tree);
	}
	else
	{
		if (tree->left != NULL)
			return (get_leaf(tree->left));
		else
			return (get_leaf(tree->right));
	}
}

/**
 * is_perfect_recursive - checks if the tree is perfect
 * @tree: pointer to the root node
 * @leaf_depth: the depth of the leaf
 * @level: the level at which the node is
 * Return: 0 or 1
 */
int is_perfect_recursive(const binary_tree_t *tree,
				size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
	{
		if (level == leaf_depth)
			return (1);
		else
			return (0);
	}
	else
	{
		if (tree->left == NULL || tree->right == NULL)
			return (0);
		else
			return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
					is_perfect_recursive(tree->right, leaf_depth, level + 1));
	}
}
