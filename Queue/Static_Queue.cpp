#include<stdio.h>
#define max 100
int queue[max],front=-1,rear=-1;
void enqueue(int val)
{
	if(rear==max-1)
	{
		printf("Queue Overflow\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=val;
	}
	else
	{
		rear++;
		queue[rear]=val;
	}
}

int dequeue()
{
	int val;
	if(front==-1 || front>rear)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		val=queue[front];
		front++;
		if(front>rear)
		front=rear=-1;
		return val;
	}
	return -1;
}

int peek()
{
	if(front==-1 || front>rear)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		return queue[front];
	}
	return -1;
}

void display()
{
	if(front==-1 || front>rear)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		int i;
		for(i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
	}
}

int main()
{
	int ch,val;
	do
	{
		printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter Value: ");
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				val=dequeue();
				if(val!=-1)
				printf("Dequeued Value: %d\n",val);
				break;
			case 3:
				val=peek();
				if(val!=-1)
				printf("Peeked Value: %d\n",val);
				break;
			case 4:
				display();
		}
		printf("\n");
	}while(ch!=5);
}
