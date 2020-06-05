#include<stdio.h>
#define max 20
int stack[max],visited[max]={0},tos=-1;

void dfs(int adj[max][max],int n,int v)
{
	int i;
	stack[++tos]=v;
	visited[v]=1;
	printf("%d ",v);
	while(tos!=-1)
	{
		v=stack[tos];
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1 && visited[i]==0)
			{
				stack[++tos]=i;
				visited[i]=1;
				printf("%d ",i);
				break;
			}
		}
		if(i==n)
		tos--;
	}
}

int main()
{
	int i,j,n,v,adj[max][max];
	printf("Enter number of vertices: ",&n);
	scanf("%d",&n);
	printf("Enter Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	printf("Enter Starting Vertex: ",&v);
	scanf("%d",&v);
	printf("DFS:\n");
	dfs(adj,n,v);
}
