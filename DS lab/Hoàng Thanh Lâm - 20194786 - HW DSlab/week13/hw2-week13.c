#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "BST2.h"
#define MAX 50

void GetDataIntoTree(BinarySearchTree *tree)
{
  FILE*file=fopen("student.txt","r+");
  if(file==NULL)
    {
      printf("Cannot open the file student.txt!\n");
      return;
    }
  else
    {
      char tmp[MAX];
      while(!feof(file))
	{
	  fgets(tmp,MAX-1,file);
	  if(!feof(file))
	     tmp[strlen(tmp)-1]='\0';
	     InsertKey(tree,tmp);
	}
    }
}

void Display(BinarySearchTree *tree)
{
  int count=0;
  PrintInorder(*tree,&count);
}

void search(BinarySearchTree *tree)
{
  char name[MAX]={};
  while(getchar() != '\n');
  printf("Input name:\n");
  scanf("%s",name);
  node *temp=Search(*tree,name);
  if(temp!=NULL) printf("%s is in the list\n",name);
  else printf("%s is not in the list\n",name);
}

void InsertName(BinarySearchTree *tree)
{
  char name[MAX]={};
  while(getchar() != '\n');
  printf("Input name:\n");
  scanf("%s",name);
  InsertKey(tree,name);
  printf("%s is insert in the tree\n",name);
}

void deletename(BinarySearchTree *tree)
{
  char namedel[MAX]={};
  while(getchar() != '\n');
  printf("Input name:\n");
  scanf("%s",namedel);
  node *del=Delete(tree,namedel);
  if(del!=NULL)
    printf("%s is clear\n",namedel);
}

void main()
{
  BinarySearchTree tree;
  MakeNull(&tree);
  printf("Getting data from file to the tree\n");
  GetDataIntoTree(&tree);
  int opt=0;
  while (opt!=5)
    {
      printf("STUDENT Management\n");
      printf("1. Display the tree\n");
      printf("2. Search name\n");
      printf("3. Delete name\n");
      printf("4. Insert name\n");
      printf("5. Exit and free the tree\n");
      printf("Enter your option:");
      scanf("%d",&opt);
      switch (opt){
      case 1: Display(&tree); break;
      case 2: search(&tree); break;
      case 3: deletename(&tree); break;
      case 4: InsertName(&tree); break;
      case 5: printf("Exit the program\n"); break;
      default: printf("Wrong syntax.Enter 1 - 5:\n");
      }
    }
}
