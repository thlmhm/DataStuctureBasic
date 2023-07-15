#include "stackstruct.h"

int main()
{
	StackType stack_int,stack_str;
	initialize(&stack_int);
	initialize(&stack_str);
	int integer;
	int opt;
	do
	{
	    printf("Undo MENU\n");
	    printf("1.Add 1 integer to the stack\n");
	    printf("2.View top\n");
	    printf("3.Remove 1 element\n");
	    printf("4.Undo\n");
	    printf("5.Exit\n");
	    printf("Your option: ");
	    scanf("%d",&opt);
	    while(getchar()!='\n');
	    switch(opt)
     {
       case 1:
       printf("Enter 1 integer: " );
       scanf("%d",&integer);
       while(getchar()!='\n');
       push(integer,&stack_int);
       push(0,&stack_str);
       break;
       
       case 2:
       if(isEmpty(&stack_int)) printf("Empty stack\n");
       else printf("%d\n",peek(&stack_int));
       break;

     case 3:
      if(isEmpty(&stack_int)) printf("Stack is Empty,can't pop\n");
      else
	  {
	   integer=pop(&stack_int);
	   push(1,&stack_str);
	  }
       break;

     case 4:
       if(isEmpty(&stack_str)) continue;
       else if(peek(&stack_str)==0)
	     {
	      integer=pop(&stack_int);
	      push(1,&stack_str);
	     }
       else if(peek(&stack_str)!=0)
	     {
	      push(integer,&stack_int);
	      push(0,&stack_str);
             }
       printf("Undo completed!\n");
       break;

     case 5: break;
     default: printf("Wrong syntax.Please enter again.\n");
	}

     } while(opt!=5);

}
