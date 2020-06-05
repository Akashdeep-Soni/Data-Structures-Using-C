#include<stdio.h>
int Fact(int n)
{
	if(n==0)
	return 1;
	else
	return n*Fact(n-1);
}

int main()
{
	int n;
	printf("Enter Number: ");
	scanf("%d",&n);
	printf("Factorial %d",Fact(n));
}
