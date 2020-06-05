#include<stdio.h>
void toh(int n,int s,int d,int a)
{
	if(n==1)
	{
		printf("%d From %c to %c\n",n,s,d);
		return;
	}
	toh(n-1,s,a,d);
	printf("%d From %c to %c\n",n,s,d);
	toh(n-1,a,d,s);
}
int main()
{
	int n;
	printf("Enter the number of disks: ");
	scanf("%d",&n);
	// Source=A Auxiliary=B Destination=C
	toh(n,'A','C','B');
}
