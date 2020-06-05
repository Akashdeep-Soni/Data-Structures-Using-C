#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct queue
{
	struct node *front;
	struct node *rear;
};

struct queue *create_queue(struct queue *q)
{
	q=(struct queue *)malloc(sizeof(struct queue));
	q->front=q->rear=NULL;
	return q;
}

struct queue *enqueue(struct queue *q,int val)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	if(q->front==NULL)
	{
		q->front=ptr;
		q->rear=ptr;
		ptr->next=NULL;
	}
	else
	{
		q->rear->next=ptr;
		q->rear=ptr;
		ptr->next=NULL;
	}
	return q;
}

int dequeue(struct queue *q)
{
	int val;
	struct node *ptr;
	if(q->front==NULL)
	{
		printf("Queue Underflow\n");
		return -1;
	}
	else
	{
		ptr=q->front;
		val=ptr->data;
		q->front=ptr->next;
		free(ptr);
	}
	return val;
}

void peek(struct queue *q)
{
	if(q->front==NULL)
	printf("Queue Underflow\n");
	else
	printf("Peeked Value: %d\n",q->front->data);
}

void display(struct queue *q)
{
	struct node *ptr;
	if(q->front==NULL)
	printf("Queue Underflow\n");
	else
	{
		ptr=q->front;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
}

int main()
{
	int ch,val;
	struct queue *q;
	q=create_queue(q);
	do
	{
		printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n.Enter Choice: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter data: ");
			scanf("%d",&val);
			q=enqueue(q,val);
		}
		else if(ch==2)
		{
			val=dequeue(q);
			if(val!=-1)
			printf("Dequeued Value: %d\n",val);
		}
		else if(ch==3)
		{
			peek(q);
		}
		else if(ch==4)
		{
			display(q);
		}
		printf("\n");
	}while(ch!=5);
}
