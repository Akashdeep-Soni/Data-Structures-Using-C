#include<stdio.h>
void bubble_sort(int a[],int n)
{
	int i,j,temp,flag;
	for(i=0;i<n-1;i++)
	{
		flag=0;//In case of partialy sorted it will reach a state when no swapping will happen 
		for(j=0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		break;
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
	
	bubble_sort(a,n);
	
	printf("Sorted Array\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
