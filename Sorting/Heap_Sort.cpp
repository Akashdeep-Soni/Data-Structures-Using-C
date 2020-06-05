#include<stdio.h>
void max_heapify(int a[],int n,int i)
{
	int left,right,largest=i,temp;
	left=2*i;
	right=2*i+1;
	if(left<=n && a[left]>a[largest])
	largest=left;
	if(right<=n && a[right]>a[largest])
	largest=right;
	if(largest!=i)
	{
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		max_heapify(a,n,largest); //the successor node need to be heapified
	}
	
}
void heap_sort(int a[],int n)
{
	int i,temp;
	for(i=n/2;i>=1;i--)
	{
		max_heapify(a,n,i); //i is the node from which heapify will occur
	}
	//Logic
	for(i=n;i>=1;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		max_heapify(a,i-1,1);
	}
}
int main()
{
	int i,n,a[10];
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	heap_sort(a,n);
	
	printf("Sorted Array\n");
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
}
