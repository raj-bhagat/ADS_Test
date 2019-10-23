#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "airline.h"


Tree tree_new()
{
Tree root ={NULL,0};
return root;
}

static Node* make_new_node(int32_t data, int32_t status, int32_t air_no)
{
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->data= data;
	new_node->status= status;
	new_node->air_no= air_no;
	new_node->right=NULL;
	new_node->left = NULL;
	return new_node;
}

Tree* add_node(Tree *t,int32_t data, int32_t status, int32_t air_no)
{
	assert(t!=NULL);
	Node *cur,*parent;
	cur=parent = t->root;
	while(cur!=NULL && cur->data!=data)
	{
		parent = cur;
		if(cur->data<data)
		{
			cur = cur->right;
		}
		else if(cur->data>data)
		{
			cur=cur->left;
		}
	}

	if(cur==NULL)
	{
		Node *new_node = make_new_node(data, status, air_no);
		if(parent==NULL)
		{
			t->root = new_node;
		}
		else if(parent->data<data)
		{
			parent->right = new_node;
		}
		else if(parent->data>data)
		{
			parent->left = new_node;
		}
		t->count++;

	}
	return t;
}


static void _inorder_(Node *n)
{
	if(n)
	{
		_inorder_(n->left);
		printf("\nAircraft number:%d",n->air_no);
		printf("\nTime:%d",n->data);
		if(n->status== 0)
		{
			printf("\nStatus:Landing");
		}
		else{
			printf("\nStatus:Take off");
		}
		_inorder_(n->right);
	} 
}

void tree_inorder(Tree *t)
{
	assert(t!=NULL);
	_inorder_(t->root);
}