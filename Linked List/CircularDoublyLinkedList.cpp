#include<stdio.h>
#include<malloc.h>
struct dnode
{
	int data;
	struct dnode *prev,*next;
}*start=NULL;

void create_ll()
{
	struct dnode *ptr,*new_dnode;
	int num;
	printf("Enter Data: ");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_dnode=(struct dnode *)malloc(sizeof(struct dnode));
		new_dnode->data=num;
		if(start==NULL)
		{
			new_dnode->next=new_dnode->prev=new_dnode;
			start=new_dnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			ptr->next=new_dnode;
			new_dnode->prev=ptr;
			new_dnode->next=start;
			start->prev=new_dnode;
		}
		printf("Enter Data: ");
		scanf("%d",&num);
	}	
}

void display()
{
	struct dnode *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->data);
}

void add_beg()
{
	struct dnode *new_dnode,*ptr;
	new_dnode=(struct dnode *)malloc(sizeof(struct dnode));
	printf("Enter Data: ");
	scanf("%d",&new_dnode->data);
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	new_dnode->next=start;
	ptr->next=new_dnode;
	start->prev=new_dnode;
	new_dnode->prev=ptr;
	start=new_dnode;
}

void add_end()
{
	struct dnode *new_dnode,*ptr;
	new_dnode=(struct dnode *)malloc(sizeof(struct dnode));
	printf("Enter Data: ");
	scanf("%d",&new_dnode->data);
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=new_dnode;
	new_dnode->prev=ptr;
	new_dnode->next=start;
	start->prev=new_dnode;
}

void delete_beg();
void delete_end();
void delete_node();
void delete_list();

int main()
{
	int ch;
	do
	{
		printf("Enter Choice\n1.Create List\n2.Display\n3.Add Beg\n4.Add End\n");
		printf("5.Delete Beg\n6.Delete End\n7.Delete Node\n8.Delete List\n9.Exit: ");
		scanf("%d",&ch);
		if(ch==1)
			create_ll();
		else if(ch==2)
			display();
		else if(ch==3)
			add_beg();
		else if(ch==4)
			add_end();
		else if(ch==5)
			delete_beg();
		else if(ch==6)
			delete_end();
		else if(ch==7)
			delete_node();
		else if(ch==8)
			delete_list();
		printf("\n");
	}while(ch!=9);
}

void delete_beg()
{
	struct dnode *ptr;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=start->next;
	start->next->prev=ptr;
	ptr=start;
	start=start->next;
	free(ptr);
}

void delete_end()
{
	struct dnode *ptr;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->prev->next=start;
	start->prev=ptr->prev;
	free(ptr);
}

void delete_node()
{
	int val;
	printf("Enter Value: ");
	scanf("%d",&val);
	struct dnode *ptr;
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}
	if(start->data==val)
	{
		delete_beg();
	}
	else
	{
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		free(ptr);
	}
}

void delete_list()
{
	struct dnode *ptr;
	ptr=start;
	while(ptr->next!=start)
		delete_end();
	free(start);
}
