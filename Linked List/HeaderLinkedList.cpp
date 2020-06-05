#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *start;

void create_ll()
{
	struct node *new_node,*ptr;
	int num;
	printf("Enter Data: ");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		new_node->next=NULL;
		if(start==NULL)
		{
			start=(struct node *)malloc(sizeof(struct node));
			start->next=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
		}
		printf("Enter Data: ");
		scanf("%d",&num);
	}
	
}

void display()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

int main()
{
	int ch;
	do
	{
		printf("Enter Choice\n1.Create List\n2.Display List\n3.Exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create_ll();break;
			case 2: display();break;
		}
		printf("\n");
	}while(ch!=3);
}
