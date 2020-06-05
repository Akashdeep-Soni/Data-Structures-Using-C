#include<stdio.h>
void merge(int a[],int lb,int mid,int ub)
{
	int i,j,k,b[10];
	i=lb;
	j=mid+1;
	k=lb;
	while(i<=mid && j<=ub)
	{
		if(a[i] <= a[j])
		{
			b[k]=a[i];
			i++;k++;
		}
		else
		{
			b[k]=a[j];
			j++;k++;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;k++;
	}
	while(j<=ub)
	{
		b[k]=a[j];
		j++;k++;
	}
	for(i=lb;i<=ub;i++)
	{
		a[i]=b[i];
	}
}

void merge_sort(int a[],int lb,int ub)
{
	if(lb < ub)
	{
		int mid=(lb+ub)/2;
		merge_sort(a,lb,mid);
		merge_sort(a,mid+1,ub);
		merge(a,lb,mid,ub);
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
	
	merge_sort(a,0,n-1);
	
	printf("Sorted Array\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
