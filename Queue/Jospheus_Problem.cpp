#include<stdio.h>
#include<malloc.h>
struct player
{
	int id;
	struct player *next;
};
int main()
{
	int i,n,k;
	struct player *start=NULL,*new_node,*ptr,*pre_ptr;
	printf("Enter Number of players: ");
	scanf("%d",&n);
	printf("Enter Step: ");
	scanf("%d",&k);
	for(i=1;i<=n;i++)
	{
		new_node=(struct player *)malloc(sizeof(struct player));
		new_node->id=i;
		if(start==NULL)
		{
			start=ptr=new_node;
			new_node->next=start;
		}
		else
		{
			ptr->next=new_node;
			new_node->next=start;
			ptr=new_node;
		}
	}
	//logic
	pre_ptr=ptr=start;
	while(--n)
	{
		for(i=1;i<k;i++)
		{
			pre_ptr=ptr;
			ptr=ptr->next;
		}
		pre_ptr->next=ptr->next;
		ptr=ptr->next;
	}
	printf("Winner %d",ptr->id);
	
}
