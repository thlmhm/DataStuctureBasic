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
int isEmpty(treetype T){
  	return T == NULL;
}
treetype LeftChild(treetype n){
  	if(n!=NULL) return n->left;
  	else return NULL;
}
treetype RightChild(treetype n){
  	if(n!=NULL) return n->right;
  	else return NULL;
}
elementtype enter_data(){
	elementtype data;
	printf("Enter data of node:");
	scanf("%d", &data);
	return data;
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
int IsLeaf(treetype n){
  	if(n!=NULL){
  		return (LeftChild(n) ==NULL) &&(RightChild(n)==NULL) ;
  	}
  	else return -1;
}
int nb_nodes(treetype T){
	if(isEmpty(T)) return 0;
	else return 1+nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
}
treetype createfrom2(elementtype v, treetype l, treetype r){
	treetype N;
	N = (node_type*)malloc(sizeof(node_type));
	N->element = v;
	N->left = l;
	N->right = r;
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
int max(int a, int b){
	if(a>=b) return a;
	else return b;
}
int height(treetype p){
	int l,r;
	if( isEmpty(p)) return 0;
	else {
		l = height(p->left);
		r = height(p->right);
		return max(l,r) + 1;
	}
}
int nb_leafs(treetype p){
	if( isEmpty(p)) return 0;
	else{
		if(p->left == NULL && p->right == NULL) return 1;
		else return nb_leafs(p->left) + nb_leafs(p->right);
	}
}
int count = 0;
int nb_internal_nodes(treetype p){
	if( isEmpty(p)) return 0;
	else{
		nb_internal_nodes(p->left);
		if( (p->left != NULL) || (p->right != NULL) ) {count++;}
		nb_internal_nodes(p->right);		
	}
	return count;
}
int countRightChild(treetype t){
    int count = 0;
    if(t == NULL){
        return count;
    }

    if(RightChild(t) != NULL){
        count ++;
    }

    count += countRightChild(LeftChild(t));
    count += countRightChild(RightChild(t));
    return count;
}
void free_tree(treetype root){
	treetype temp;
	temp = root;
	if(isEmpty(temp)) return;
	free_tree(temp->left);
	free_tree(temp->right);
	if( !isEmpty(temp->left) && !isEmpty(temp->right)){
		free(temp);
		return;
	}
}
