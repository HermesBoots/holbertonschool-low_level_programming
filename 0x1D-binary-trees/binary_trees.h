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
int binary_tree_balance(binary_tree_t const *tree);
int binary_tree_is_full(binary_tree_t const *tree);
int binary_tree_is_perfect(binary_tree_t const *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(
	binary_tree_t const *first,
	binary_tree_t const *second
);
void do_tree_levelorder(binary_tree_t const *, void (*)(int), size_t);
void binary_tree_levelorder(binary_tree_t const *tree, void (*func)(int));
int binary_tree_is_complete(binary_tree_t const *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(binary_tree_t const *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(bst_t const *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(binary_tree_t const *tree);
void retrace_avl(avl_t *tree, int side);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
void do_avl_from_sorted(int *array, size_t size, avl_t *node);
avl_t *sorted_array_to_avl(int *array, size_t size);

#endif
