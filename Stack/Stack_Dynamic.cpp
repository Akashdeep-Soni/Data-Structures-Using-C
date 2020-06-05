#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *push(struct node *tos,int val)
{
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		new_node->data=val;
		new_node->next=tos;
		tos=new_node;
	}
	return tos;
}

struct node* pop(struct node *tos)
{
	struct node *ptr;
	if(tos==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		ptr=tos;
		tos=tos->next;
		printf("Popped Item: %d\n",ptr->data);
		free(ptr);
	}
	return tos;
}

struct node *display(struct node *tos)
{
	struct node *ptr;
	ptr=tos;
	if(ptr==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
	return tos;
}

int peek(struct node *tos)
{
	if(tos==NULL)
	return -1;
	else
	return tos->data;
}

int main()
{
	int ch,val;
	struct node *tos=NULL;
	do
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Peek\nEnter Choice: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter Value: ");
			scanf("%d",&val);
			tos=push(tos,val);
		}
		else if(ch==2)
		tos=pop(tos);
		else if(ch==3)
		tos=display(tos);
		else if(ch==4)
		{
			val=peek(tos);
			if(val!=-1)
			printf("Peeked Item: %d\n",val);
			else
			printf("Stack Underflow\n");
		}
	}while(ch!=5);
}
