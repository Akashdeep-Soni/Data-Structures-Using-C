#include<stdio.h>
//Element range <= Number of elements
//Negatives are not allowed
//No comparision happens
void count_sort(int a[],int n)
{
	int i,j,max,b[10];
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	int count[max+1]={0};
	
	for(i=0;i<n;i++)
	{
		count[a[i]]++;
	}
	
	for(i=1;i<=max;i++)
	{
		count[i]+=count[i-1];
	}
	
	//For stable(Don't disturb order of same value) sorting
	for(i=n-1;i>=0;i--)
	{
		b[--count[a[i]]]=a[i];
	}
	
	for(i=0;i<n;i++)
	{
		a[i]=b[i];
	}
	
}

int main()
{
	int i,n,a[10];
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	count_sort(a,n);
	
	printf("Sorted Array\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
