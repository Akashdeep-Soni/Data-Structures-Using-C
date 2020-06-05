#include<stdio.h>
#include<ctype.h>
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

float eval_postfix(char exp[])
{
	int i=0;
	float a,b;
	while(exp[i]!='\0')
	{
		if(isdigit(exp[i]))
		{
			push((float)exp[i++]-'0');
		}
		else
		{
			b=pop();
			a=pop();
			switch(exp[i])
			{
				case '+': push(a+b);break;
				case '-': push(a-b);break;
				case '*': push(a*b);break;
				case '/': push(a/b);break;
				case '%': push(float(int(a)%int(b)));break;
			}
			i++;
		}
	}
	return stack[tos];
}

int main()
{
	float val;
	char exp[max];
	printf("Enter Expression: ");
	gets(exp);
	val=eval_postfix(exp);
	printf("Value After Evaluation: %.2f",val);
}
