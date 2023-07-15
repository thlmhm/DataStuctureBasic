#include<stdio.h>
#define MAX 50
typedef int Eltype;
typedef Eltype StackType[MAX];
int top;

void initialize(StackType stack){
	top = 0;
}
int isEmpty(StackType stack){
	return top ==0;
}
int isFull(StackType stack){
	return top == MAX;
}
void push(Eltype el, StackType stack){
	if(isFull(stack)){
		printf("Stack overflow");
	}
	else stack[top++] = el;
}
Eltype pop(StackType stack){
	if(isEmpty(stack)){
		printf("Stack underflow");
	}
	else {
		return stack[--top];
	}
}
Eltype peek(StackType stack){
	if(isEmpty(stack)){
		printf("Stack underflow");
		return -999999;
	}
	else return stack[top-1];
}


