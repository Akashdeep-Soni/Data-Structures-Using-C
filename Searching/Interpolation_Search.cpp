#include<stdio.h>
//Array should be sorted
//Numbers should be uniform or fairly uniform (Difference between two consecutive elements should be same or try to be same)
int interpolation_search(int a[],int beg,int end,int val)
{
	int pos;
	while(beg<=end)
	{
		if(beg==end)
		{
			if(val==a[beg])
			return beg;
			break;
		}
		pos=beg+((val-a[beg])*(end-beg))/(a[end]-a[beg]); //if beg and end same, Diferrence will be zero, Element will be same, 0/0 division occur, logical error
		if(val==a[pos])
		return pos;
		else if(val < a[pos])
		end=pos-1;
		else
		beg=pos+1;
	}
	return  -1;
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
		
	pos=interpolation_search(a,0,n-1,val);
	
	if(pos!=-1)
	printf("Item found at index %d",pos);
	else
	printf("Item not found");
}
