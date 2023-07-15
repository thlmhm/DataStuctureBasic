#include<stdio.h>
#define MAX 50

typedef int Elementype;

typedef struct StackRecord
{
    Elementype storage[MAX];
    int top;
} StackType;

void initialize(StackType *stack)
{
    (*stack).top=0;
}

int isEmpty(StackType*stack)
{
    if((*stack).top==0)
    return 1;
    else return 0;
}

int isFull(StackType *stack)
{
    if((*stack).top==MAX)
    return 1;
    else return 0;
}

void push(Elementype new, StackType *stack)
{
    if(isFull(stack)==1)
    {
        printf("The stack is full. Can't push the new element.\n");
        return;
    }
    else
    {
        (*stack).storage[(*stack).top]=new;
        (*stack).top++;
    }
}

Elementype pop(StackType *stack)
{
    if(isEmpty(stack)==1)
    {
        printf("The stack is empty. Cann't pop the element.\n");
        return 0;
    }
    else
    {
        Elementype remove;
        remove=(*stack).storage[(*stack).top-1];
        (*stack).top=(*stack).top-1;
        printf("Remove is successful.\n");
        return remove;
    }
}

Elementype peek(StackType *stack)
{
    if(isEmpty(stack)==1)
    return 0;
    else return (*stack).storage[(*stack).top-1];
}

int Size(StackType *stack)
{
    return (*stack).top;
}
