#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int elementtype;
typedef struct nodetype{
  	elementtype element;
  	struct nodetype *left,*right;
}node_type;
typedef struct nodetype* treetype;

void MakeNullTree(treetype *T){
  	(*T)=NULL;
}

node_type *create_node(elementtype NewData){
  	node_type *N;
  	N = (node_type*)malloc(sizeof(node_type));
  	if(N != NULL){
  	  	N->left = NULL;
  	  	N->right = NULL;
  	  	N->element = NewData;
  	}
  	return N;
}

treetype Add_Left(treetype *Tree, elementtype NewData){
	node_type *NewNode = create_node(NewData);
	if (NewNode == NULL) return (NewNode);
	if (*Tree == NULL) *Tree = NewNode;
	else{	
		node_type *Lnode = *Tree;
		while (Lnode->left != NULL) {
			Lnode = Lnode->left;}	
		Lnode->left = NewNode;
	}
	return (NewNode);
}

treetype Add_Right(treetype *Tree, elementtype NewData){
	node_type *NewNode = create_node(NewData);
	if (NewNode == NULL) return (NewNode);
	if (*Tree == NULL) *Tree = NewNode;
	else{
		node_type *Rnode = *Tree;
		while (Rnode->right != NULL) 
			Rnode = Rnode->right;
		Rnode->right = NewNode;
	}
	return (NewNode);
}
