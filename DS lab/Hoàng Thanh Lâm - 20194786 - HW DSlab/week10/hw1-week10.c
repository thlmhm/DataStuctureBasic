#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char elementtype;

typedef struct node
{
    elementtype data;
    struct node *link;
} StackType;

StackType *Push(StackType *p, elementtype value)
{
    StackType *temp;
    temp=(StackType*)malloc(sizeof(StackType));
    if(temp  == NULL)
    {
        printf("No memory available.\n");
        return NULL;
    }
    else
    {
        temp->data = value;
        temp->link = p;
        p = temp;
        return p;
        
    }
}
StackType *Pop(StackType *p, elementtype *value)
{
    StackType *temp;
    if(p == NULL)
    {
        printf("The stack is empty. Cannot pop.\n");
        return NULL;
    }
    else
    {
        *value= p->data;
        temp=p;
        p=p->link;
        free(temp);
        return p;
        
    }
}
elementtype Top(StackType *p)
{
    if(p == NULL)
    {
        printf("Stack is empty! Cannot get the top element.\n");
        return 0;
    }
    else 
        return p->data;
}
int Size(StackType *p)
{
    int count=0;
    StackType *temp;
    for(temp=p;temp!=NULL;temp=temp->link)
    {
        count++;
    }
    return count;
}
StackType* FreeStack(StackType *p)
{
    StackType *temp;
    temp=p;
    while(p!=NULL)
    {
        p=p->link;
        free(temp);
        temp=p;
    }
    return p;
}
void main()
{
    StackType *p1=NULL,*p2=NULL,*psum=NULL;
    char num1,num2;
    int result=0,a,b,carry=0;
    int size1,size2;
    printf("Enter the first number:\n");
    
    while (scanf("%c", &num1) > 0)
    {
        if (num1 == '\n')
        {
            break;
        }
        p1 = Push(p1, num1);
    }
    
    fflush(stdin);
    printf("Enter the second number:\n");
    
    while (scanf("%c", &num2) > 0)
    {
        if (num2 == '\n')
        {
            break;
        }
        p2 = Push(p2, num2);
    }
    
    size1 = Size(p1); 
    size2 = Size(p2);
    printf("The size1:%d\n",size1);
    printf("The size2:%d\n",size2);
    do{
        if(size1 !=0)
        {
            p1=Pop(p1,&num1);
            a=num1 -'0';
            size1--;
        }
        else if(size1==0) a=0;
        if(size2!=0)
        {
            p2=Pop(p2,&num2);
            b=num2-'0';
            size2--;
        }
        else if(size2==0) b=0;
        result= a+b+carry;
        carry=result/10;
        result=result%10;
        psum=Push(psum,result+'0');
    } while(size1!=0||size2!=0);
    
    if(carry==1)
    {
        psum=Push(psum,carry+'0');
    }
    
    int sizesum;
    sizesum=Size(psum);
    printf("The sum size :%d\n",sizesum);
    printf("The value is: ");
    
    for(int i=0;i<sizesum;i++)
    {
        char c;
        psum=Pop(psum,&c);
        printf("%c",c);
    }
    printf("\n");
    p1=FreeStack(p1);
    p2=FreeStack(p2);
    psum=FreeStack(psum);
}
