#include<stdio.h>
#define max 10
int main()
{
	int adj[max][max],i,j,k,n;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	printf("Enter Adjacent Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
			if(adj[i][j]==0 && i!=j)
			adj[i][j]=999; //The node which are not reachable should be maximum
		}
	}
	
	//Logic
	for(k=0;k<n-1;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if( adj[i][j] > ( adj[i][k] + adj[k][j] ) )
				adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}
	
	printf("All Pair Shortest Path\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",adj[i][j]);
		printf("\n");
	}
	

}
