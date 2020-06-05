#include<stdio.h>
#include<math.h>
//Array should be sorted
int jump_search(int a[],int n,int val)
{
	int i,lb,ub,step=sqrt(n); //Number of steps
	lb=0;
	ub=step; //Steps to be jumped
	while(ub<n && a[ub]<val)  //If val is bigger then jump
	{
		lb=ub;
		ub+=step;
	}
	if(ub>=n) //If boundary is passed
	ub=n-1;
	for(i=lb;i<=ub;i++)
	{
		if(val==a[i])
		return i;
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
		
	pos=jump_search(a,n,val);
	
	if(pos!=-1)
	printf("Item found at index %d",pos);
	else
	printf("Item not found");
}
