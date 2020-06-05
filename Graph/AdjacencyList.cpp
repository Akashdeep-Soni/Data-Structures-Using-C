#include<stdio.h>
#include<stdlib.h>
struct node
{
	int vertex;
	struct node *next;
};

void create_graph(struct node *a[],int n)
{
	int i,j,m,val;
	struct node *ptr,*new_node;
	for(i=0;i<n;i++)
	{
		ptr=NULL;
		printf("Enter the number of neighbours of vertex %d: ",i);
		scanf("%d",&m);
		
		for(j=1;j<=m;j++)
		{
			printf("Enter the neighbour %d of %d: ",j,i);
			scanf("%d",&val);
			new_node=(struct node *)malloc(sizeof(struct node));
			new_node->vertex=val;
			new_node->next=NULL;
			
			if(a[i]==NULL)
			a[i]=new_node;
			else
			ptr->next=new_node;
			
			ptr=new_node;
		}
	}
}

void display_graph(struct node *a[10],int n)
{
	int i;
	struct node *ptr;
	printf("\nAdjacency List\n");
	for(i=0;i<n;i++)
	{
		ptr=a[i];
		printf("The neighbours of vertex %d are ",i);
		while(ptr!=NULL)
		{
			printf("%d ",ptr->vertex);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void delete_graph(struct node *a[10],int n)
{
	int i;
	struct node *ptr,*temp;
	for(i=0;i<n;i++)
	{
		ptr=a[i];
		while(ptr!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
			free(temp);
		}
		a[i]=NULL;
	}
}

int main()
{
	int i,n;
	struct node *adj[10];
	printf("Enter number of vertex: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	adj[i]=NULL;
	create_graph(adj,n);
	display_graph(adj,n);
	delete_graph(adj,n);
}
