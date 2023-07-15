#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct data{
	char name[30];
	double grade;
}data_t;
typedef data_t elementtype;
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
/*elementtype enter_data(){
	elementtype data;
	printf("Enter data of node:");
	scanf("%d", &data);
	return data;
}*/
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
void inorderprint(treetype tree){
	if(tree!=NULL){
		inorderprint(tree->left);
		printf("%-15s%-4.2lf\n", tree->element.name,tree->element.grade);
		inorderprint(tree->right);
	}
}/*
void postorderprint(treetype tree){
	if(tree!= NULL){
		postorderprint(tree->left);
		postorderprint(tree->right);
		printf("%4d\n", tree->element);
		
	}
}
void preorderprint(treetype tree){
	if(tree!=NULL){
		printf("%4d\n", tree->element);
		preorderprint(tree->left);
		preorderprint(tree->right);
	}
}*/
/*
treetype Search(elementtype x,treetype Root){
	if (Root == NULL) return NULL; // not found
	else if (Root->element == x) 
		return Root;
	else if (Root->element < x) //continue searching in the right sub tree
		return Search(x,Root->right);
	else  // continue searching in the left sub tree
		return Search(x,Root->left);
}*/
void InsertNode(elementtype x,treetype *Root ){
	if (*Root == NULL){
	/* Create a new node for key x */
		*Root = (node_type*)malloc(sizeof(node_type));
		(*Root) -> element.grade = x.grade;
		strcpy((*Root) -> element.name , x.name);
		(*Root) -> left = NULL;
		(*Root) -> right = NULL;
	}
	else if (x.grade < ((*Root)->element.grade)) InsertNode(x, &(*Root)->left);
	else if (x.grade > ((*Root)-> element.grade)) InsertNode(x, &(*Root)->right);
}
/*
treetype InsertNode2(elementtype x, treetype root){
	if(root == NULL){
		root = (node_type*)malloc(sizeof(node_type));
		root -> element = x;
		root -> left = NULL;
		root -> right = NULL;
		return root;
	}
	else if( x < (root->element)) return InsertNode2(x, root->left);
	else if(x > (root->element)) return InsertNode2(x, root->right);
}*/
elementtype DeleteMin(treetype *root){
	elementtype k;
	if((*root)->left == NULL){
		k = (*root)->element;
		(*root) = (*root)->right;
		return k;
	}
	else return DeleteMin(&(*root)->left);
}/*
void DeleteNode(int x, treetype *root){
	if(*root != NULL){
		if(x <(*root)->element) DeleteNode(x,&(*root)->left);
		else if (x > (*root)->element)
			DeleteNode(x, &(*root) -> right);
		else if
		(((*root)->left ==NULL) && ((*root)->left ==NULL)) 
			*root == NULL;
		else if ((*root)->left == NULL)
			*root = (*root) -> right;
		else if ((*root)->right == NULL)
			*root = (*root) -> left;
		else (*root)->element = DeleteMin(&(*root)->right);
	}
}*/
int lower_than_key(double grade,treetype root)
{
	if(root!=NULL){
		if(root->element.grade < grade){
			printf("%-30s%.2lf\n",root->element.name,root->element.grade);
			return 1+lower_than_key(grade,root->left)+lower_than_key(grade,root->right);
		}
		else return lower_than_key(grade,root->left)+lower_than_key(grade,root->right) ;
	}
	else return 0;
}
int higher_than_key(double grade,treetype root)
{
	if(root!=NULL)
    	{
		if(root->element.grade>grade){	
			printf("%-30s%.2lf\n",root->element.name,root->element.grade);
			return 1 + higher_than_key(grade,root->left) + higher_than_key(grade,root->right);
		}
		else return higher_than_key(grade,root->left)+higher_than_key(grade,root->right) ;
	}
	else return 0;
}
//void enter_data(elementtype){
	
//}
int main(){
	//int a[10] = {4, 9, 5, 100, 26, -18, 13, 77, 1, 34};
	elementtype a[10];
	int i,s;
	int del;
	treetype root;
	printf("Enter data!\n");
	for(i=0; i<3;i++){
		printf("Enter name of student %d:", i+1);
		scanf("%s", a[i].name);
		while(getchar() != '\n');
		printf("Enter grade of student %d:", i+1);
		scanf("%lf", &a[i].grade); 
	}
	MakeNullTree(&root);
	for(i=0;i<3;i++){
		InsertNode(a[i],&root);
	}
	printf("Inorder print :\n");
	inorderprint(root);
	printf("Enter key: ");
	scanf("%d", &s);
	int ltk;
	ltk = lower_than_key(s, root);
	printf("Number of element: %d\n", ltk);
	free_tree(root);
	return 0;
}

