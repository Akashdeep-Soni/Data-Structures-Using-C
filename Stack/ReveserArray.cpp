#include<stdio.h>
#include<stdlib.h>
#define size 10
int st[size],tos=-1;

void push(int val)
{
	st[++tos]=val;
}

int pop()
{
	return st[tos--];
}

int main()
{
	int *a,i,n;
	printf("Number of elements: ");
	scanf("%d",&n);
	a=(int*)calloc(sizeof(int),n);
	printf("Enter %d elements: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",(a+i));
	}
	
	for(i=0;i<n;i++)
	{
		push(*(a+i));
	}
	
	for(i=0;i<n;i++)
	{
		*(a+i)=pop();
	}
	printf("Reversed Array: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(a+i));
	}
	
}
