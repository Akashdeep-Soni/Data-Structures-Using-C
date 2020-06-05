#include<stdio.h>
#include<malloc.h>
struct dnode
{
	int data;
	struct dnode *prev,*next;
}*start=NULL;

void create_list()
{
	struct dnode *new_dnode,*ptr;
	char ch;
	do
	{
		new_dnode=(struct dnode *)malloc(sizeof(struct dnode));
		printf("Enter Data: ");
		scanf("%d",&new_dnode->data);
		new_dnode->prev=new_dnode->next=NULL;
		if(start==NULL)
		{
			start=new_dnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next=new_dnode;
			new_dnode->prev=ptr;
		}
 		printf("Do you want to enter more dnode: ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch!='n');
}

void display_list()
{
	struct dnode *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void add_beg()
{
	struct dnode *new_dnode;
	new_dnode=(struct dnode *)malloc(sizeof(struct dnode));
	printf("Enter Data: ");
	scanf("%d",&new_dnode->data);
	new_dnode->prev=NULL;
	new_dnode->next=start;
	start->prev=new_dnode;
	start=new_dnode;
}

void add_end()
{
	struct dnode *ptr,*new_node;
	new_node=(struct dnode *)malloc(sizeof(struct dnode *));
	printf("Enter Data: ");
	scanf("%d",&new_node->data);
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
}

void add_before()
{
	struct dnode *ptr,*new_node;
	new_node=(struct dnode *)malloc(sizeof(struct dnode *));
	printf("Enter Data: ");
	scanf("%d",&new_node->data);
	int val;
	printf("Enter Value: ");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	ptr=ptr->next;
	ptr->prev->next=new_node;
	new_node->prev=ptr->prev;
	new_node->next=ptr;
	ptr->prev=new_node;	
}

void add_after()
{
	struct dnode *ptr,*new_node;
	new_node=(struct dnode *)malloc(sizeof(struct dnode *));
	printf("Enter Data: ");
	scanf("%d",&new_node->data);
	int val;
	printf("Enter Value: ");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	ptr=ptr->next;
	new_node->next=ptr->next;
	new_node->prev=ptr;
	ptr->next->prev=new_node;
	ptr->next=new_node;
}

void delete_beg()
{
	struct dnode *ptr;
	ptr=start;
	start=start->next;
	start->prev=NULL;
	free(ptr);
}

void delete_end()
{
	struct dnode *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->prev->next=NULL;
	free(ptr);
}

void delete_before()
{
	struct dnode *ptr,*temp;
	int val;
	printf("Enter Value: ");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	ptr=ptr->next;
	temp=ptr->prev;
	if(temp==start)
	delete_beg();
	else
	{
		ptr->prev->prev->next=ptr;
		ptr->prev=ptr->prev->prev;
		free(temp);
	}
	
}

void delete_after()
{
	struct dnode *ptr,*temp;
	int val;
	printf("Enter Value: ");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	ptr=ptr->next;
	temp=ptr->next;
	if(temp->next==NULL)
	delete_end();
	else
	{
		ptr->next=temp->next;
		ptr->next->prev=ptr;
		free(temp);
	}
	
}

void delete_list();

int main()
{
	int ch;
	do
	{
		printf("Enter Choice\n1.Create List\n2.Display List\n3.Add Beg\n4.Add End\n5.Add Before\n6.Add After\n");
		printf("7.Delete Beg\n8.Delete End\n9.Delete Before\n10.Delete After\n11.Delete List\n12.Exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create_list();break;
			case 2: display_list();break;
			case 3: add_beg();break;
			case 4: add_end();break;
			case 5: add_before();break;
			case 6: add_after();break;
			case 7: delete_beg();break;
			case 8: delete_end();break;
			case 9: delete_before();break;
			case 10: delete_after();break;
			case 11: delete_list();break;
		}
		printf("\n");
	}while(ch!=12);
}

void delete_list()
{
	struct dnode *ptr;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		delete_beg();
		
	}
}
