#include<stdio.h>
#define max 20
int q[max],visited[max]={0},f=-1,r=-1;

void bfs(int adj[max][max],int n,int v)
{
	int i;
	q[++r]=v;
	visited[v]=1;
	while(f!=r)
	{
		v=q[++f];
		printf("%d ",v);
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1 && visited[i]==0)
			{
				q[++r]=i;
				visited[i]=1;
			}
		}
	}
}
int main()
{
	int i,j,n,v,adj[max][max];
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	printf("Enter matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	printf("Enter the source vertex: ");
	scanf("%d",&v);
	printf("BFS:\n");
	bfs(adj,n,v);
}
