#include<stdio.h>
#define max 10
int tos=-1;

void push(int st[],int val)
{
	if(tos==max-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		st[++tos]=val;
	}
}

int pop(int *st)
{
	int val;
	if(tos==-1)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
	{
		val=st[tos--];
		return val;
	}
}

void display(int *st)
{
	int i;
	if(tos==-1)
	printf("Stack Underflow\n");
	else
	for(i=tos;i>-1;i--)
	{
		printf("%d ",st[i]);
	}
}

int peek(int st[])
{
	if(tos==-1)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
	{
		return st[tos];
	}
}

int main()
{
	int ch,val,st[max];
	do
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Peek\nEnter Choice: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter Value: ");
			scanf("%d",&val);
			push(st,val);
		}
		else if(ch==2)
		{
			val=pop(st);
			if(val!=-1)
			printf("Popped Item: %d\n",val);
		}
		else if(ch==3)
		display(st);
		else if(ch==4)
		{
			val=peek(st);
			if(val!=-1)
			printf("Peeked Item: %d\n",val);
		}
	}while(ch!=5);
}
