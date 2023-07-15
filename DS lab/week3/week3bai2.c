#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    FILE* fptr1;
    FILE* fptr2;
    char ch1,ch2;
    int key;
    
  if(argc != 4)
    {
      printf("The number of arguments is wrong.\n");
      printf("CORRECT SYNTAX:mahoa_caesar <file1> <key_number> <file2>\n");
      return 1;
    }
  
  fptr1=fopen(argv[1],"r");
  fptr2=fopen(argv[3],"w");
  key=atoi(argv[2]);
  
  if(fptr1 == NULL || fptr2 == NULL)
    {
      printf("Can not open the files: %s or %s.\n", argv[1],argv[3]);
      return 1;
    }
  else {
    ch1 = fgetc(fptr1);
  while(ch1 != EOF)
    {
      if ( ('z'-ch1) < key )
	{
	  ch2 = ' ' + key - ('z' - ch1 + 1);
	  fputc(ch2,fptr2);
	} else
	{ ch2 = ch1 + key;
	  fputc(ch2,fptr2);}
      ch1 = fgetc(fptr1);
    } 
  }
  fclose(fptr1);
  fclose(fptr2);
  return 0;
  
}

