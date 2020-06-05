//Refer disjoint set data structure (Find & Union operation in array) first

#include<stdio.h>
#define max 10
int parent[max]={0};

int find(int i)
{
	while(parent[i]!=0)
	i=parent[i];
	return i;
}

int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	else
	return 0;
}

int main()
{
	int adj[max][max],i,j,k,u,v,a,b,n,min,mincost=0;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	printf("Enter Adjacent Matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&adj[i][j]);
			if(adj[i][j]==0)
			adj[i][j]=999;
		}
	}
	
	//logic
	printf("Minimus Spanning Tree\n");
	for(k=1;k<n;) // for n vertices n-1 edge looping n-1 times
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(adj[i][j] < min)
				{
					min=adj[i][j];
					u=a=i;
					v=b=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		
		if(uni(u,v)==1)
		{
			printf("%d Edge (%d,%d) =%d\n",k++,a,b,min);
			mincost+=min;
		}
		
		adj[a][b]=adj[b][a]=999;
	}
	printf("Minimum Cost: %d",mincost);
	
}
