#include<stdio.h>
#include<string.h>
#define max 10
char st[max];
int tos=-1;

void push(char sbl)
{
	st[++tos]=sbl;
	printf("\nPushed %c",st[tos]);
}

char pop()
{
	printf("\nPopped %c",st[tos]);
	return st[tos--];
}

int main()
{
	char exp[max],sbl,temp;
	int i,flag=1;
	printf("Enter Expression: ");
	gets(exp);
	for(i=0;i<strlen(exp);i++)
	{
		sbl=exp[i];
		printf("%c ",sbl);
		if(sbl=='(' || sbl=='{' || sbl=='[')
		{	
			push(sbl);
		}
		else if(sbl==')' || sbl=='}' || sbl==']')
		{
			printf("Hello %c",sbl);
			if(tos==-1)
			{
				flag=0;
				break;
			}
			
			temp=pop();
			printf("\nTemp %c ",temp);
			if(sbl==')' && (temp=='{' || temp=='['))
			flag=0;
			if(sbl=='}' && (temp=='(' || temp=='['))
			flag=0;
			if(sbl==']' && (temp=='(' || temp=='{'))
			flag=0;
		}
		printf("\n");
	}
	if(tos>-1)
	flag=0;
	if(flag==1)
	printf("\nExpression Valid");
	else
	printf("\nExpression Invalid");
}
