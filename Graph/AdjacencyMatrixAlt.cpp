#include<stdio.h>
int main()
{
	int i,j,n,u,v,val,adj[10][10]={0},max_edge;
	printf("Enter number of vertex: ");
	scanf("%d",&n);
	max_edge=n*(n-1); //n vertices can have max n-1 edges hence total
	//Scanning Matrix
	for(i=0;i<max_edge;i++)
	{
		printf("Enter Edge %d (u,v) or (-1,-1) to stop: ",i+1);
		scanf("%d%d",&u,&v);
		if(u==-1 && v==-1)
		break;
		else if(u>=n || v>=n || u<0 || v<0)
		{
			printf("Invalid Edge\n");
			i--;
		}
		else
		adj[u][v]=1;
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
