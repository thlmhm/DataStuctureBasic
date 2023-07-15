#include "stacklib.h"
#define MAX 100

int precedence(char x)
{
    if(x=='(')
    { return 0;}
    if(x=='+'||x=='-')
    {return 1;}
    if(x=='*'||x=='/'||x=='%')
    {return 2;}
    else
    return 3;
}

void InfixtoPostfix(char infix[],char postfix[])
{
    typedef char elementtype;
    StackType *S=NULL;
    char token,x;
    int i=0,j=0;
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(token>='0'&& token <='9')
        {
            postfix[j++]=token;
            postfix[j++]=' ';
        }
        else if(token=='(')
        {
            S=Push(S,token);
        }
        else if(token==')')
        {
            while (1)
            {
                x = Top(S);
                if (x == '(')
                {
                    S = Pop(S);
                    break;
                }
                postfix[j++] = x;
                postfix[j++]=' ';
                S = Pop(S);
            }
        }
        else 
        {
            while (precedence(token)<=precedence(Top(S))&&Empty(S)==0)
            {
                postfix[j++] = Top(S);
                postfix[j++] =' ';
                S = Pop(S);
            }
            S=Push(S,token);
        }
    }
    while(Empty(S)==0)
    {
        x=Top(S);
        printf("%c\n",x);
        S=Pop(S);
        postfix[j++] = ' ';
        postfix[j++]=x;
    }
    postfix[j]='\0';
}

int Evaluate(char Postfix[])
{
    StackType *S=NULL;
    int i,num1,num2,result;
    for(i=0;Postfix[i]!='\0';i++)
    {
        if(Postfix[i]==' '||Postfix[i]=='\t')
        {
            i++;
        }
        else if(Postfix[i]>='0'&&Postfix[i]<='9')
        {
            S=Push(S,Postfix[i]);
        }
        else
        {
            num1=Top(S)-'0';
            S=Pop(S);
            num2=Top(S)-'0';
            S=Pop(S);
            if(Postfix[i]=='+')
            {
                result=num1+num2;
                S=Push(S,result+'0');
            }
            else if(Postfix[i]=='-')
            {
                result=num2-num1;
                S=Push(S,result+'0');
            }
            else if(Postfix[i]=='*')
            {
                result=num2*num1;
                S=Push(S,result+'0');
            }
            else if(Postfix[i]=='/')
            {
                result=num2/num1;
                S=Push(S,result+'0');
            }
            else
            {
                printf("The expression is wrong\n");
                return 0;
            }
        }
    }
    result=Top(S)-'0';
    S=Pop(S);
    return result;
}

int main()
{  int opt = 0;
  char A[MAX], B[MAX];
  int result;
  while (opt != 4)
    {
      printf("CHANGE INFIX TO POSTFIX\n");
      printf("1.Enter the infix exxpression\n");
      printf("2.Change to postfix\n");
      printf("3.Calculate\n");
      printf("4.Exit\n");
      printf("Enter your option:\n");
      scanf("%d",&opt);
      switch(opt)
	{
	case 1:
	  printf("Enter the Infix:\n");
	  scanf("%s",A);
	  break;
	case 2:
	  InfixtoPostfix(A,B);
	  printf("%s\n",B);
	  break;
	case 3:
	  result = Evaluate(B);
	  printf("The solution is %d\n", result);
	  break;
	case 4:
	  printf("Exit\n");
	  break;
	default:
	  printf("The option is wrong\n");
	  printf("Enter again(1-4).\n");
	}
    }
    return 0;
}
