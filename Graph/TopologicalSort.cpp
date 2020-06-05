#include<stdio.h>
#define max 20
int adj[max][max]={0},indeg[max],q[max],f=-1,r=-1,n;

void enqueue(int val)
{
	if(f==-1 && r==-1)
	f=0;
	q[++r]=val;
}

int dequeue()
{
	int val;
	if(f==-1 && r==-1)
	return -1;
	val=q[f++];
	if(f>r)
	f=r=-1;
	return val;
}

int find_indeg(int v)
{
	int i,val=0;
	for(i=0;i<n;i++)
	{
		if(adj[i][v]==1)
		val++;
	}
	return val;
}

void topological_sort()
{
	int i,v;
	//Calculating Indegree of all vertices
	for(i=0;i<n;i++)
	{
		indeg[i]=find_indeg(i);
		if(indeg[i]==0)
		enqueue(i);
	}
	
	v=dequeue();
	while(v!=-1)
	{
		printf("%d ",v);
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1)
			{
				indeg[i]-=1;
				adj[v][i]=0;
				if(indeg[i]==0)
				enqueue(i);
			}	
		}
		v=dequeue();
	}
}

int main()
{
	int i,j,me,u,v;
	printf("Enter Number of vertex: ");
	scanf("%d",&n);
	me=n*(n-1);
	//Reading Matrix
	for(i=0;i<me;i++)
	{
		printf("Enter edge %d (u,v) or (-1,-1) to stop: ",i+1);
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
	//Writing Matrix
	printf("Adjacency Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",adj[i][j]);
		printf("\n");
	}
	printf("Topological Sorted:\n");
	topological_sort();
}
