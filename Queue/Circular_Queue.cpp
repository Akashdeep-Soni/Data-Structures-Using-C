#include<stdio.h>
#define max 3
int queue[max],f=-1,r=-1;

void enqueue(int data)
{
	if(f==(r+1)%max)
	{
		printf("Queue Overflow\n");
	}
	else if(f==-1 && r==-1)
	{
		f=r=0;
		queue[r]=data;
	}
	else
	{
		r=(r+1)%max;
		queue[r]=data;
	}
}

int dequeue()
{
	int val=-1;
	if(f==-1 && r==-1)
	{
		printf("Queue Underflow\n");
	}
	else if(f==r)
	{
		val=queue[f];
		f=r=-1;
	}
	else
	{
		val=queue[f];
		f=(f+1)%max;
	}
	return val;
}

void peek()
{
	if(f==-1 && r==-1)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		printf("%d",queue[f]);
	}
}

void display()
{
	if(f==-1 && r==-1)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		int i=f;
		while(i!=r)
		{
			printf("%d ",queue[i]);
			i=(i+1)%max;
		}
		printf("%d ",queue[i]);
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
				printf("Enter Data: ");
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				val=dequeue();
				if(val!=-1)
				printf("Dequeued Value %d",val);
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
		}
		printf("\n");
	}while(ch!=5);
}
