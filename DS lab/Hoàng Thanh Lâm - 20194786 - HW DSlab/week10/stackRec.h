#include<stdio.h>
#define MAX 50
typedef int Eltype;
typedef struct StackRec{
	Eltype storage[MAX];
	int top;
}StackRec;
typedef struct StackRec StackType;

void initialize(StackType *stack){
	(*stack).top = 0;
}
int isEmpty(StackType *stack){
	return (*stack).top ==0;
}
int isFull(StackType *stack){
	return (*stack).top == MAX;
}
void push(Eltype el, StackType *stack){
	if(isFull(stack)){
		printf("Stack overflow");
	}
	else (*stack).storage[(*stack).top++] = el;
}
Eltype pop(StackType *stack){
	if(isEmpty(stack)){
		printf("Stack underflow");
	}
	else {
		return (*stack).storage[--(*stack).top];
	}
}
Eltype peek(StackType *stack){
	if(isEmpty(stack)){
		printf("Stack underflow");
		return -999999;
	}
	else return (*stack).storage[(*stack).top -1];
}

//stack->top=0;


