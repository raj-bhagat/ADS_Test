#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "airline.h"

int main()
{
	int32_t data[] = {9, 1540, 7, 1900, 1870, 1560, 1930, 1610, 1700, 1730};
	int32_t status[] = {TAKE_OFF, LANDING, LANDING, LANDING, LANDING, TAKE_OFF, TAKE_OFF, TAKE_OFF, LANDING, TAKE_OFF };
	int32_t air_no[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	Tree bst = tree_new();
	Tree *tree = &bst;
	for(int i=0;i<11;++i){
		tree = tree = add_node(tree,data[i], status[i], air_no[i]);
	}
	printf("The schedule is:");
	tree_inorder(tree);
	return 0;
}