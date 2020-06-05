#include<stdio.h>
int exp(int n,int p)
{
	if(p==0)
	return 1;
	else
	return n*exp(n,p-1);
}
int main()
{
	int n,p;
	printf("Enter Number And Power: ");
	scanf("%d %d",&n,&p);
	printf("Exponent Value: %d",exp(n,p));
}
