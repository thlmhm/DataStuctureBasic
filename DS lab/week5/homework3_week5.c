#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void main()
{

	FILE *fin, *fout;
	fin=fopen("vnedict.txt","r");
    char c;
	int count=0;
	if (fin == NULL)
	{
		printf("Cannot open the file vnedict.txt\n");
	}
	else
	{   
		fout = fopen("vnedict.dat", "wb");
		while (fread(&c, sizeof(char), 1, fin)> 0)
		{
			if (c == '\n')
			{
				count++;
			}
			fwrite(&c, sizeof(char), 1, fout);
		}
	
		rewind(fout);
		fclose(fout);
		rewind(fin);
		fout = fopen("vnedict.dat", "rb");
		if (fout == NULL)
		{
			printf("Cannot open the file vnedict.dat\n");
		}
		else
		{   	
			rewind(fout);
			int begin = 0, end = 0;
			do
			{
				printf("Enter the begin number display the word:\n");
				scanf("%d", &begin);
				if (begin <= 0)
				{
					printf("The begin number must be positive\n");
				}
			} while (begin <= 0);
			do
			{
				printf("Enter the end number display the word:\n");
				scanf("%d", &end);
				if (end <= 0)
				{
					printf("The end number must be positve\n");
				}
				if (end - begin < 0)
				{
					printf("The end number must be bigger than the begin number\n");
				}
			} while (end <= 0 || (end - begin < 0));
			count =0;
		  while (fread(&c, sizeof(char), 1, fout)> 0)
		{   
			if(count == begin){
				break;
			}
			if (c == '\n')
			{
				count++;
			}
		}
		  while (fread(&c, sizeof(char), 1, fout)> 0)
		{
			if (c == '\n')
			{
				count++;
			}
			printf("%c",c);
			if(count == end+1){
				break;
			}
		}

		}
	}
	rewind(fin);
	rewind(fout);
	fclose(fin);
	fclose(fout);
}
