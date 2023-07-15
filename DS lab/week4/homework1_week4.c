#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define M 80
char *subStr(FILE*s1, int offset, int number)
{
  char *sub;
  int count=0;

  if (fseek(s1,offset*sizeof(char),SEEK_SET) != 0)
    {
      printf("Fseek failed!\n");
    }
  if(offset<=0)
    {
      printf("Offset must be positive.\n");
    }
  if(number<=0)
    {
      printf("Number must be positive.\n");
    }
    else
    {
      fseek(s1,offset*sizeof(char),SEEK_SET);
      sub=(char*)malloc((number+1)*sizeof(char));
      count= fread(sub,sizeof(char),number*sizeof(char),s1);
      sub[count*sizeof(char)]='\0';
      if(count<number)
	{
	  printf("The number is greater than the number of characters resting from offset to the end of s1.\n");
	}
	return sub;
    }
  free(sub);
}
int main()
{
  FILE*s1;
  int offset;
  int number;
  s1=fopen("lab1.txt","r");
  if ((s1 = fopen("lab1.txt", "r")) == NULL)
    {
      printf("Cannot open lab1.txt.\n");
      return 1;
    }
  printf("The index that subString starts from:\n");
  scanf("%d",&offset);
  printf("The number of characters you want to take from:\n");
  scanf("%d",&number);
  printf("The substring is:%s\n",subStr(s1,offset,number));
  fclose(s1);
  return 0;
}
  
  
      
