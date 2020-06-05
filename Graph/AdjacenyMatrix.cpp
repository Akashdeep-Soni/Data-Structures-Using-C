#include<stdio.h>
int main()
{
	int i,j,n,val,adj[10][10];
	printf("Enter number of vertex: ");
	scanf("%d",&n);
	//Scanning Matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter edge from %d to %d ",i,j);
			scanf("%d",&val);
			adj[i][j]=val;
		}
	}
	//Your Matrix
	printf("\nAdjaceny Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
}
