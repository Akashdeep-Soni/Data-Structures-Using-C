#include<stdio.h>
int linear_search(int a[],int n,int val)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(val==a[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int a[10],i,n,pos,val;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter value to be searched: ");
	scanf("%d",&val);
	
	pos=linear_search(a,n,val);
	
	if(pos!=-1)
	{
		printf("Item found at index %d",pos);
	}
	else
	{
		printf("Item not found");
	}
}
