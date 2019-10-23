#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
#include<stdint.h>
#include<assert.h>

typedef struct _tree_ Tree;
typedef struct _node_ Node;
#define LANDING 0
#define TAKE_OFF 1

struct _tree_
{
	Node *root;
	int32_t count;
};

struct _node_
{
	int32_t data;
	int32_t status;
	int32_t air_no;
	Node *left;
	Node *right;
};
Tree tree_new();
Tree* add_node(Tree *t,int32_t data, int32_t status, int32_t air_no);
void tree_inorder(Tree *t);

#endif