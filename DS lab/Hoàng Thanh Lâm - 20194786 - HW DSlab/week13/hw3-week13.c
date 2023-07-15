#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "BST3.h"

#define MAX 100

elementtype ReadInfor()
{
  elementtype tmp;
  printf("Enter name of the phone:\n");
  scanf("%s",tmp.name);
  printf("Enter memory space:\n");
  scanf("%s",tmp.memoryspace);
  printf("Enter screen size:\n");
  scanf("%s",tmp.screensize);
  printf("Enter the price:\n");
  scanf("%d",&tmp.price);
  return tmp;
}

void export(BinarySearchTree *tree, FILE*file)
{
      if(*tree == NULL) {printf("Null2\n");return;}
      export(&(*tree)->left, file);
      fwrite(&(*tree)->key, sizeof(elementtype), 1, file);
      export(&(*tree)->right, file);
}

void bai1(BinarySearchTree *tree)
{
  FILE *file;
  char name[MAX];
  printf("Enter name of file:\n");
  scanf("%s%*c",name);
  file=fopen(name,"r");
  if(file==NULL)
    {
      printf("Cannot open the file %s\n",name);
      return;
    }
  else
    {
      MakeNull(tree);
      elementtype cat;
      while(fscanf(file,"%s %s %s %d%*c",cat.name,cat.memoryspace,cat.screensize,&cat.price)!=EOF)
	{  InsertKey(tree,cat);
	}
      printf("Successful!\n");
    }
  fclose(file);
}

void bai2(BinarySearchTree *tree)
{
  FILE *file;
  char name[MAX];
  printf("Enter name of file:\n");
  scanf("%s%*c",name);
  file=fopen(name,"rb");
  if(file==NULL)
    {
      printf("Cannot open the file %s\n",name);
      return;
    }
  else
    {
      MakeNull(tree);
      elementtype cat;
      while(fread(&cat,sizeof(catalog),1,file)>0)
	{
	  InsertKey(tree,cat);
	}
      printf("Successful!\n");
    }
  fclose(file);
}

void bai3(BinarySearchTree *tree)
{
  int count=0;
  PrintInorder(*tree,&count);
}

void bai4(BinarySearchTree *tree)
{
  elementtype x;
  printf("Enter information new phone:\n");
  x=ReadInfor();
  InsertKey(tree,x);
  printf("Successful!\n");
}

void bai5(BinarySearchTree *tree)
{
  char name[MAX];
  printf("Enter the name of a phone:\n");
  scanf("%s%*c",name);
  node *temp=Search(*tree,name);
  if(temp!=NULL) printf("%s is in the list\n",name);
  else printf("%s is not in the list\n",name);
  
}

void bai6(BinarySearchTree *tree)
{
  char name[MAX];
  printf("Enter the name of a phone:\n");
  scanf("%s%*c",name);
 node*k= Delete(tree,name);
 if(k!=NULL) printf("Successful!\n");
}
void bai7(BinarySearchTree *tree)
{
  char name[MAX];
  printf("Enter the name of a phone:\n");
  scanf("%s%*c",name);
  Delete(tree,name);
  elementtype x;
  printf("Updating data:\n");
  x=ReadInfor();
  InsertKey(tree,x);
  printf("Successful!\n");
}
/*
void bai8(BinarySearchTree *tree)
{
  FILE*fout=fopen("PhoneDB.dat","wb+");
  if(fout==NULL)
    {
      printf("Cannot open the file %s\n","PhoneDB.dat");
      return;
    }
  else
    {
      if(*tree==NULL) return;
      else
	{
	  export(tree,fout);
	}
    }
  fclose(fout);
}
*/
void main()
{
  BinarySearchTree tree;
  int opt=0;
  FILE*fout=fopen("PhoneDB.dat","wb+");
  if(fout==NULL)
    {
      printf("Cannot open the file %s\n","PhoneDB.dat");
      return;
    }
  while (opt != 9) {
  printf("=======MENU========\n");
  printf("1.Import from Text\n");
  printf("2.Import from Dat\n");
  printf("3.Display the tree (inorder)\n");
  printf("4.Add phone model\n");
  printf("5.Search phone by Model\n");
  printf("6.Delete phone\n");
  printf("7.Search and Update\n");
  printf("8.Export to file DAT\n");
  printf("9.Exit and free tree\n");
  printf("Enter your option\n");
  scanf("%d",&opt);
  switch (opt) {
  case 1: bai1(&tree); break;
  case 2: bai2(&tree); break;
  case 3: bai3(&tree); break;
  case 4: bai4(&tree); break;
  case 5: bai5(&tree); break;
  case 6: bai6(&tree); break;
  case 7: bai7(&tree); break;
  case 8: 
  export(&tree, fout); 
  fclose(fout);
  break;
  case 9: printf("Exit the program!\n"); FreeTree(&tree); break;
  default: printf("Wrong syntax. Enter 1 - 9 \n\n");
  }
    }

}
