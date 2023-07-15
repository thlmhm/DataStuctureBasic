#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 50

typedef char elementtype[MAX];

typedef struct Node
{
    elementtype key;
    struct Node* left, *right;
}node;

typedef struct Node* BinarySearchTree;

void MakeNull(BinarySearchTree *tree)
{
    (*tree)=NULL;
}

node * MakeNewNode(elementtype x)
{
    node* new=(node*)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("Cannot allocate memory!\n");
        return NULL;
    }
    else
    {
        strcpy(new->key,x);
        new->left=NULL;
        new->right=NULL;
        return new;
    }
}

int EmptyTree(BinarySearchTree tree)
{
    if(tree==NULL) return 1;
    else return 0;
}

node* LeftChild(node *n)
{
    if(n!=NULL) return n->left;
    else return NULL;
}

node* RightChild(node *n)
{
    if(n!=NULL) return n->right;
    else return NULL;
}

void InsertKey(BinarySearchTree *tree,elementtype x)
{
 
        if(*tree==NULL) *tree=MakeNewNode(x);
        else
        {
	  if(strcmp(x,(*tree)->key)<0) InsertKey(&((*tree)->left),x);
            else InsertKey(&((*tree)->right),x);
        }
}

node* Search(BinarySearchTree tree, elementtype x)
{
    if(tree==NULL) return NULL;
    else if(strcmp((tree)->key,x)==0) return tree;
    else if(strcmp((tree)->key,x)<0)  return Search(((tree)->right),x);
    else return Search(((tree)->left),x);
}

node* FindMin(BinarySearchTree tree)
{
    if(tree==NULL) return NULL;
    else
    {
        if((tree)->left==NULL) return tree;
        else return FindMin(((tree)->left));
    }
}

node*FindMax(BinarySearchTree tree)
{
    if((tree)==NULL) return NULL;
    else
    {
        if((tree)->right==NULL) return tree;
        else return FindMax(((tree)->right));
    }
}

node *Delete(BinarySearchTree *tree,elementtype x)
{
    node *tmp;
    if((*tree)==NULL) printf("Not found\n");
    else if(strcmp(x,(*tree)->key)<0) (*tree)->left=Delete(&((*tree)->left),x);
    else if(strcmp(x,(*tree)->key)>0) (*tree)->right=Delete(&((*tree)->right),x);
    else
    {
        if(LeftChild(*tree)!=NULL&&RightChild(*tree)!=NULL)
        {
            tmp=FindMin((*tree)->right);
            strcpy((*tree)->key,tmp->key);
            (*tree)->right=Delete(&((*tree)->right),(*tree)->key);
        }
        else 
        {
            tmp=*tree;
            if((*tree)->left==NULL) *tree=(*tree)->right;
            else if((*tree)->right==NULL) *tree=(*tree)->left;
            free(tmp);
        }
    }
    return (*tree);
}
//cac ham giong nhu cay binary tree

int IsLeaf(node *n)
{
    if(n!=NULL&&LeftChild(n)==NULL&&RightChild(n)==NULL) return 1;
    else return 0;
}

int NumberNode(BinarySearchTree tree)
{
    if(tree==NULL) return 0;
    else return 1+NumberNode(LeftChild(tree))+NumberNode(RightChild(tree));
}

node *CreateFrom2nodes(elementtype newdata, node*Left,node*Right)
{
    node* n;
    n=(node*)malloc(sizeof(node));
    strcpy(n->key,newdata);
    n->left=Left;
    n->right=Right;
    return n;
}

node* AddLeft(BinarySearchTree*tree,elementtype newdata)
{
    node *new=MakeNewNode(newdata);
    if(new==NULL) printf("Cannot alllocate memory!\n");
    else
    {
        if((*tree)==NULL) *tree=new;
        else 
        {
            node *Left=*tree;
            while(Left->left!=NULL) Left=Left->left;
            Left->left=new;
        }
    }
    return new;
}

node * AddRight(BinarySearchTree *tree,elementtype newdata)
{
    node *new=MakeNewNode(newdata);
    if(new==NULL) printf("Cannot allocate memory!\n");
    else
    {
        if(*tree==NULL) *tree=new;
        else 
        {
            node *Right=*tree;
            while(Right->right!=NULL) Right=Right->right; 
            Right->right=new;
        }
        return new;
    }
}

int Height(node *root)
{
    if(root==NULL) return 0;
    else {int ld= Height(root->left);
    int rd=Height(root->right);
    if(ld>rd) return 1+ld;
    else return 1+rd;}
}

int CountLeaf(node *root)
{
    if(root==NULL) return 0;
    else if(IsLeaf(root)==1) return 1;
    else{
        int leftleaf=CountLeaf(root->left);
        int rightleaf=CountLeaf(root->right);
        return leftleaf+rightleaf;
    }
}

int Internalnodes(node*root)
{
    if(root==NULL) return 0;
    else
    {
        if(IsLeaf(root)==1) return 0;
        else
        {
            int left=Internalnodes(root->left);
            int right=Internalnodes(root->right);
            return 1+left+right;
        }
    }
}

int HasRightChild(node* n)
{
    if(n==NULL) return 0;
    else
    {
        if(n->right==NULL) return 0;
        else return 1;
    }
}

int CountRightChild(node*root)
{
    if(HasRightChild(root)==0) return 0;
    else return 1 + CountRightChild(root->left)+ CountRightChild(root->right);
} 
void PrintNode(node *p)
{
    printf("%s\n",p->key);
}
void PrintPreorder(node *tree)
{
    if(tree==NULL) return;
    else
    {
        printf("%s\t ",tree->key);
        PrintPreorder(tree->left);
        PrintPreorder(tree->right);
    }
}
void PrintPostorder(node *tree)
{
    if(tree==NULL) return;
    else
    {
        PrintPostorder(tree->left);
        PrintPostorder(tree->right);
         printf("%s\t ",tree->key);
    }
}
void PrintInorder(node *tree, int *count)
{
    if(tree==NULL) return;
    else
    {
        PrintInorder(tree->left,count);
        printf("%d. %s\n",++(*count),tree->key);
        PrintInorder(tree->right,count);
    }
}
void FreeTree(BinarySearchTree *tree)
{
    if(*tree==NULL) return;
    else 
    {
        FreeTree(&((*tree)->left));
        FreeTree(&((*tree)->right));
        free(*tree);
    }
}



