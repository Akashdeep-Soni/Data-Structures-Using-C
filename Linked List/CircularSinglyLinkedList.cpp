#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL;

void create_ll()
{
	
	struct node *new_node,*ptr;
	char ch;
	do
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->next=NULL;
		printf("Enter Data:");
		scanf("%d",&new_node->data);
		
		if(start==NULL)
		{
			start=new_node;
			new_node->next=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=start;
		}
		fflush(stdin);
		printf("Press 'n' to stop else 'y':");
		scanf("%c",&ch);
	}while(ch!='n');
}

void display()
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->data);
}

void add_beg();
void add_end();

void delete_beg()
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	
	
}

void delete_end()
{
	struct node *preptr,*ptr;
	ptr=preptr=start;
	while(ptr->next!=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=start;
	free(ptr);
}

void delete_after()
{
	struct node *preptr,*ptr;
	preptr=start;
	ptr=preptr->next;
	int val;
	printf("Enter Value: ");
	scanf("%d",&val);
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	if(ptr==start)
	{
		start=preptr->next;
		
	}
	free(ptr);
}

void delete_list();

int main()
{
	struct node;
	char ch;
	do
	{
		fflush(stdin);
		printf("Enter choice\n1.Create List\n2.Display\n3.Add Beg\n4.Add End\n5.Delete Beg");
		printf("\n6.Delete End\n7.Delete After Node\n8.Delete List\n9.EXIT:");
		scanf("%c",&ch);
		switch(ch)
		{
			case '1': create_ll();break;
			case '2': display();break;
			case '3': add_beg();break;
			case '4': add_end();break;
			case '5': delete_beg();break;
			case '6': delete_end();break;
			case '7': delete_after();break;
			case '8': delete_list();break;
		}
		printf("\n");
	}while(ch!='9');
}

void add_beg()
{
	struct node *ptr,*new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->next=NULL;
	printf("Enter Data:");
	scanf("%d",&new_node->data);
	
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;
}

void add_end()
{
	struct node *ptr,*new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->next=NULL;
	printf("Enter Data:");
	scanf("%d",&new_node->data);
	
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
}

void delete_list()
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		delete_end();
	}
	free(start);
}
