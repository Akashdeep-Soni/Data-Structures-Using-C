#include<stdio.h>
void selection_sort(int a[],int n)
{
	int i,j,temp,loc;
	for(i=0;i<n-1;i++)
	{
		loc=i;
		for(j=i+1;j<n;j++)
		{
			if(a[loc] > a[j])
			{
				loc=j;
			}
		}
		if(loc!=i)
		{
			temp=a[i];
			a[i]=a[loc];
			a[loc]=temp;
		}
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
	
	selection_sort(a,n);
	
	printf("Sorted Array\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
