#include <stdio.h>
#include <string.h>
#include <ctype.h> 
 

char checkCapital(char *str2)
    {
        static int i = 0;
        if (i < strlen(str2))
        {
            if (isupper(str2[i]))
            {
                return str2[i];
            }
            else
            {
                i = i + 1;
                return checkCapital(str2);
            }
        }
        else return 0;
    
   }
 
int main()
{
    char str1[20], singLet;
	
    printf("\n Recursion : Find the first capital letter in a string :\n");
    printf(" Input a string to including one or more capital letters : ");
    scanf("%s", str1);
    singLet = checkCapital(str1);
    if (singLet == 0)
    {
        printf(" There is no capital letter in the string :  %s.\n", str1);
    }
    else
    {
        printf(" The first capital letter appears in the string %s is %c.\n\n", str1, singLet);    }
        return 0;
}


