#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(binary_tree_t const *root);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(binary_tree_t const *node);
int binary_tree_is_root(binary_tree_t const *node);
void binary_tree_preorder(binary_tree_t const *tree, void (*func)(int));
void binary_tree_inorder(binary_tree_t const *tree, void (*func)(int));
void binary_tree_postorder(binary_tree_t const *tree, void (*func)(int));
size_t do_tree_height(binary_tree_t const *tree, size_t height);
size_t binary_tree_height(binary_tree_t const *tree);
size_t binary_tree_depth(binary_tree_t const *tree);
size_t binary_tree_size(binary_tree_t const *tree);
size_t binary_tree_leaves(binary_tree_t const *tree);
size_t binary_tree_nodes(binary_tree_t const *tree);

#endif
