#include<stdio.h>
int partition(int a[],int lb,int ub)
{
	int i,j,pivot,temp;
	pivot=lb;
	i=lb;
	j=ub;
	while(i<j)
	{
		while(a[i]<=a[pivot])
		{
			i++;
		}
		while(a[j]>a[pivot])
		{
			j--;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	
	temp=a[pivot];
	a[pivot]=a[j];
	a[j]=temp;
	
	return j;
}

void quick_sort(int a[],int lb,int ub)
{
	if(lb < ub)
	{
		int loc= partition(a,lb,ub);
		quick_sort(a,lb,loc-1);
		quick_sort(a,loc+1,ub);
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
	
	quick_sort(a,0,n-1);
	
	printf("Sorted Array\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
