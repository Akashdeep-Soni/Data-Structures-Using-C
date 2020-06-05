#include<stdio.h>
#define max 10
int main()
{
	int adj[max][max],visited[max]={0},i,j,k,u,v,n,min,mincost=0;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	printf("Enter Adjacent Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
			if(adj[i][j]==0)
			adj[i][j]=999; //The node which are not weighted should be minimum
		}
	}
	
	//Logic
	printf("Minimum Spanning Tree\n");
	visited[0]=1;
	for(k=1;k<n;k++)
	{
		min=999;
		for(i=0;i<n;i++)
		{
			if(visited[i]==1)
			for(j=0;j<n;j++)
			{
				if(visited[j]==0 && adj[i][j] < min)
				{
					min=adj[i][j];
					u=i;
					v=j;
				}
			}
		}
		visited[v]=1;
		mincost+=min;
		adj[u][v]=adj[v][u]=999;
		printf("%d Edge (%d,%d) = %d\n",k,u,v,min);
	}
	
	printf("Minimum Cost: %d",mincost);
}
