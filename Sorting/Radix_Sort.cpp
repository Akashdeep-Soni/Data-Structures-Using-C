#include<stdio.h>
int get_max(int a[],int n)
{
	int i,max=a[0];
	for(i=0;i<n;i++)
	{
		if(max < a[i])
		{
			max=a[i];
		}
	}
	return max;
}

void count_sort(int a[],int n,int pos)
{
	int i,count[10]={0},b[n];
	for(i=0;i<n;i++)
	{
		count[(a[i]/pos)%10]++;
	}
	for(i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		b[--count[(a[i]/pos)%10]]=a[i];
	}
	for(i=0;i<n;i++)
	{
		a[i]=b[i];
	}
}

void radix_sort(int a[],int n)
{
	int pos,max=get_max(a,n);
	for(pos=1;max/pos>0;pos*=10)
	{
		count_sort(a,n,pos);
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
	
	radix_sort(a,n);
	
	printf("Sorted Array\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
