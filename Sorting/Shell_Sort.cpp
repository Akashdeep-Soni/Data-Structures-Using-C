#include<stdio.h>
//Same as insertion sort with introduction to gap 
//Use only if smaller elements are left side
void shell_sort(int a[],int n)
{
	int i,j,gap,temp;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			temp=a[i];
			for(j=i-gap;j>=0 && a[j]>temp;j-=gap)
			{
				a[j+gap]=a[j];
			}
			a[j+gap]=temp;
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
	
	shell_sort(a,n);
	
	printf("Sorted Array\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
