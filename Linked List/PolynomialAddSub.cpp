#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff,power;
	struct node *next;
};

struct node *create_poly(struct node * start)
{
	int c,p;
	struct node *ptr,*new_node;
	printf("Enter Power: ");
	scanf("%d",&p);
	while(p!=-1)
	{
		printf("Enter Coefficiant: ");
		scanf("%d",&c);
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->next=NULL;
		new_node->power=p;
		new_node->coeff=c;
		if(start==NULL)
		{
			start=new_node;
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
		printf("Enter Power: ");
		scanf("%d",&p);
	}
	return start;
}

void display_poly(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%dx%d ",ptr->coeff,ptr->power);
		ptr=ptr->next;
	}
	printf("\n");
}

struct node *add_node(struct node* start,int c,int p)
{
		struct node *new_node,*ptr;
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->next=NULL;
		new_node->power=p;
		new_node->coeff=c;
		if(start==NULL)
		{	
			start=new_node;
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
		return start;
}

struct node *add_poly(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *ptr1,*ptr2;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->power == ptr2->power)
		{
			start3=add_node(start3,ptr1->coeff + ptr2->coeff,ptr1->power);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->power > ptr2->power)
		{
			start3=add_node(start3,ptr1->coeff,ptr1->power);
			ptr1=ptr1->next;
		}
		else if(ptr2->power > ptr1->power)
		{
			start3=add_node(start3,ptr2->coeff,ptr2->power);
			ptr2=ptr2->next;
		}
	}
	while(ptr1!=NULL)
	{
		start3=add_node(start3,ptr1->coeff,ptr1->power);
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL)
	{
		start3=add_node(start3,ptr2->coeff,ptr2->power);
		ptr2=ptr2->next;
	}
	return start3;
}

struct node *sub_poly(struct node *start1,struct node *start2,struct node *start4)
{
	struct node *ptr1,*ptr2;
	ptr1=start1;ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->power == ptr2->power)
		{
			start4=add_node(start4,ptr1->coeff - ptr2->coeff,ptr1->power);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->power > ptr2->power)
		{
			start4=add_node(start4,ptr1->coeff,ptr1->power);
			ptr1=ptr1->next;
		}
		else if(ptr1->power < ptr2->power)
		{
			start4=add_node(start4,ptr2->coeff,ptr2->power);
			ptr2=ptr2->next;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			start4=add_node(start4,ptr2->coeff,ptr2->power);
			ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			start4=add_node(start4,ptr1->coeff,ptr1->power);
			ptr1=ptr1->next;
		}
	}
	return start4;
}

int main()
{
	struct node *start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL;
	int ch;
	do
	{
		printf("Enter Choice\n1.Create Poly 1\n2.Display Poly 1\n3.Create Poly 2\n4.Display Poly 2\n");
		printf("5.Add Poly\n6.Display Add\n7.Sub Poly\n8.Display Sub\n9.Exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: start1=create_poly(start1);break;
			case 2: display_poly(start1);break;
			case 3: start2=create_poly(start2);break;
			case 4: display_poly(start2);break;
			case 5: start3=add_poly(start1,start2,start3);break;
			case 6: display_poly(start3);break;
			case 7: start4=sub_poly(start1,start2,start4);break;
			case 8: display_poly(start4);break;
		}
		printf("\n");
	}while(ch!=9);
}
