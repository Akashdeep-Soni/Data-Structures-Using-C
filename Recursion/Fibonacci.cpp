#include<stdio.h>
int Fib(int n)
{
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	else return Fib(n-1)+Fib(n-2);
}
int main()
{
	int n;
	printf("Enter Range: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",Fib(i));
	}
}
