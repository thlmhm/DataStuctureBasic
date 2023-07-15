#include <stdio.h>
#include <string.h>

int main()
{
    int num = 0;
    int i;
    printf("Input number of student: ");
    scanf("%d", &num);
    while(getchar() != '\n');
    char name[num][100] = {};
    
    for(i = 0; i < num; i++)
    {
        printf("Input name of student %d: ", i+1);
        gets(name[i]);
    }
    
    char nameToCheck[100] = {};
    printf("Input first name to check: ");
    gets(nameToCheck);
    int count = 0;
    
    for(int i = 0; i < num; i++)
    {
        if(strstr(name[i], nameToCheck) != 0)
        {
            count++;
        }
    }
    printf("Number of student has first name %s: %d", nameToCheck, count);

    return 0;
}
