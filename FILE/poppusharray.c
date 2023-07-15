

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int *array;
int count;
void pop(int a)
{
    
    
    if(array==NULL)
    {
        array=(int*)malloc(sizeof(int));
        array[0]=a;
        count=1;
    }
    else
    {
        array=(int*)realloc(array,(count+1)*sizeof(int));
        array[count]=a;
        count++;
    }
}
void push()
{
    if(array==NULL)
    {
        return;
    }
    else
    {
        array=(int*)realloc(array,(count)*sizeof(int));
        count--;
    }
}
void main()
{
    int a;
    for(int i=0;i<4;i++)
    {
        printf("enter %d number:",i+1);
        scanf("%d",&a);
        pop(a);
    }
    for(int i=0;i<4;i++)
    {
        printf("%d\n",array[i]);
    }
    push();
    for(int i=0;i<3;i++)
    {
        printf("%d\n",array[i]);
    }
    free(array);
}
