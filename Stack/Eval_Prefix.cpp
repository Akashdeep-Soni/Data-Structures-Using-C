#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100
float stack[max];
int tos=-1;

void push(float val)
{
	if(tos==max-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		stack[++tos]=val;
	}
}

float pop()
{
	if(tos==-1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		return stack[tos--];
	}
}

float eval_prefix(char exp[])
{
	int i;
	i=strlen(exp)-1;
	float a,b;
	while(i>=0)
	{
		if(isdigit(exp[i]))
		{
			push((float)(exp[i--]-'0'));
		}
		else
		{
			a=pop();
			b=pop();
			switch(exp[i])
			{
				case '+': push(a+b);break;
				case '-': push(a-b);break;
				case '*': push(a*b);break;
				case '/': push(a/b);break;
				case '%': push(int(a)%int(b));break;
			}
			i--;
		}
	}
}

int main()
{
	float val;
	char exp[max];
	printf("Enter Expression: ");
	gets(exp);
	val=eval_prefix(exp);
	printf("Value After Evaluation: %.2f",val);
}
