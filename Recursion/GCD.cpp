#include<stdio.h>
int gcd(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
int main()
{
	int a,b;
	printf("Enter two number: ");
	scanf("%d%d",&a,&b);
	printf("GCD %d",gcd(a,b));
}
