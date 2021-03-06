#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define max 100
char stack[max];
int tos=-1;

void push(char ch)
{
	if(tos==max-1)
	{
		printf("Stack Overflow\n");
		exit(0);
	}
	else
	{
		stack[++tos]=ch;
	}
}

char pop()
{
	if(tos==-1)
	{
		printf("stack Underflow\n");
		exit(0);
	}
	else
	{
		char temp=stack[tos];
		tos--;
		return temp;
	}
}

int symbol(char ch)
{
	if(ch=='^' || ch=='*' || ch=='/' || ch=='+' || ch=='-')
	{
		return 1;
	}
	return 0;
}

int priority(char ch)
{
	if(ch=='^')
	return 3;
	else if(ch=='*' || ch=='/')
	return 2;
	else if (ch=='+' || ch=='-')
	return 1;
}

void infixtopostfix(char infix[],char postfix[])
{
	char sbl,temp;
	int i,j;
	i=j=0;
	push('(');
	strcat(infix,")");
	while(infix[i]!='\0')
	{
		sbl=infix[i];
		if(sbl=='(')
		{
			push(sbl);
			i++;
		}
		else if(sbl==')')
		{
			temp=pop();
			while(temp!='(')
			{
				postfix[j++]=temp;
				temp=pop();
			}
			i++;
		}
		else if(isalnum(sbl))
		{
			postfix[j++]=sbl;
			i++;
		}
		else if(symbol(sbl))
		{
			temp=pop();
			while(temp!='(' && priority(temp)>=priority(sbl))
			{
				postfix[j++]=temp;
				temp=pop();
			}
			push(temp);
			push(sbl);
			i++;
		}
	}
	postfix[i]='\0';
}

int main()
{
	char infix[max],postfix[max];
	printf("Enter Expression: ");
	gets(infix);
	infixtopostfix(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);
}
