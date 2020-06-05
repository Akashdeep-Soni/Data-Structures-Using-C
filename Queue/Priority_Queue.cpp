#include<stdio.h>
#include<malloc.h>
struct node 
{
	int data,priority;
	struct node *next;
}*start=NULL;

struct node *insert_node(struct node * start)
{
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data and Priority: ");
	scanf("%d%d",&new_node->data,&new_node->priority);
	if(start==NULL || new_node->priority < start->priority)
	{
		new_node->next=start;
		start=new_node;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL && ptr->next->priority <=new_node->priority)
		{
			ptr=ptr->next;
		}
		new_node->next=ptr->next;
		ptr->next=new_node;
	}
	return start;
}

struct node *delete_node(struct node *start)
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		ptr=start;
		printf("Deleted Node Data %d Priority %d\n",ptr->data,ptr->priority);
		start=start->next;
		free(ptr);
	}
	return start;
}

void display()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("Data %d Priority %d\n",ptr->data,ptr->priority);
			ptr=ptr->next;
		}
	}
}

int main()
{
	int ch;
	do
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: start=insert_node(start);break;
			case 2: start=delete_node(start);break;
			case 3: display();break;
		}
	}while(ch!=4);
}
