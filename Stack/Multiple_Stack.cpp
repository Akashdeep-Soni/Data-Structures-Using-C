#include<stdio.h>
#define size 5
int stack[size],tosA=-1,tosB=size;

void pushA(int val)
{
	if(tosA==tosB-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		stack[++tosA]=val;
	}
}

int popA()
{
	if(tosA==-1)
	{
		printf("Stack Underflow\n");
		return -999;
	}
	else
	{
		return stack[tosA--];
	}
}

void displayA()
{
	int i;
	if(tosA==-1)
	printf("Stack Underflow\n");
	else
	for(i=tosA;i>-1;i--)
	{
		printf("%d ",stack[i]);
	}
}

void pushB(int val)
{
	if(tosB==tosA+1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		stack[--tosB]=val;
	}
}

int popB()
{
	if(tosB==size)
	{
		printf("Stack Underflow\n");
		return -999;
	}
	else
	{
		return stack[tosB++];
	}
}

void displayB()
{
	int i;
	if(tosB==size)
	printf("Stack Underflow\n");
	else
	for(i=tosB;i<size;i++)
	{
		printf("%d ",stack[i]);
	}
}

int main()
{
	int ch,val;
	do
	{
		printf("1.Push A\n2.Pop A\n3.Display A\n4.Push B\n5.Pop B\n6.Display B\n7.Exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter Value: ");
				scanf("%d",&val);
				pushA(val);
				break;
			case 2:
				val=popA();
				if(val!=-999)
				printf("Popped Item %d\n",val);
				break;
			case 3:
				displayA();
				break;
			case 4:
				printf("Enter Value: ");
				scanf("%d",&val);
				pushB(val);
				break;
			case 5:
				val=popB();
				if(val!=-999)
				printf("Popped Item %d\n",val);
				break;
			case 6:
				displayB();
				break;
		}
		printf("\n");
	}while(ch!=7);
}
