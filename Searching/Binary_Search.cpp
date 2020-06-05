#include<stdio.h>
//Array should be sorted
int binary_search(int a[],int beg,int end,int val)
{
	int mid;
	while(beg <= end)
	{
		mid=(beg+end)/2;
		if(val==a[mid])
		{
			return mid;
		}
		else if(val < a[mid])
		{
			end=mid-1;
		}
		else
		{
			beg=mid+1;
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
		
	pos=binary_search(a,0,n-1,val);
	
	if(pos!=-1)
	printf("Item found at index %d",pos);
	else
	printf("Item not found");
}
