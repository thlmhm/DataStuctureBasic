#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef char elementtype;

typedef struct node
{
    elementtype data;
    struct node *link;
}StackType;

StackType *Push(StackType *p, elementtype value)
{
    StackType *temp;
    temp=(StackType*)malloc(sizeof(StackType));
    if(temp==NULL)
    {
        printf("No memory available.\n");
        return NULL;
    }
    else
    {
        temp->data=value;
        temp->link=p;
        p=temp;
        return p;
        
    }
}

StackType *Pop(StackType *p)
{
    StackType *temp;
    int value;
    if(p==NULL)
    {
        return NULL;
    }
    else
    {
        value= p->data;
        temp=p;
        p=p->link;
        free(temp);
        return p;
        
    }
}

elementtype Top(StackType *p)
{
    if(p==NULL)
    {
        return 'o';
    }
    else return p->data;
}

int Size(StackType *p)
{
    int size=0;
    StackType *temp;
    for(temp=p;temp!=NULL;temp=temp->link)
    {
        size++;
    }
    return size;
}

StackType* FreeStack(StackType *p)
{
    StackType *temp=p;
    while(p!=NULL)
    {
        p=p->link;
        free(temp);
        temp=p;
    }
    return p;
}

int Empty(StackType* p)
{
    if(p==NULL)
    return 1;
    else return 0;
}
