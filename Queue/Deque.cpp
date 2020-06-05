#include<stdio.h>
#define max 4
int deque[max],left=-1,right=-1;

void input_right()
{
	int val;
	if((left==0 && right==max-1) ||left==right+1)
	{
		printf("Overflow\n");
	}
	else if(left==-1 && right==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(right==max-1)
		right=0;
		else
		right++;
	}
	printf("Enter Data: ");
	scanf("%d",&val);
	deque[right]=val;
}

void input_left()
{
	int val;
	if((left==0 && right==max-1)|| left==right+1)
	printf("Overflow\n");
	else if(left==-1 && right==-1)
	{
		left=0;right=0;
	}
	else
	{
		if(left==0)
		left=max-1;
		else
		left--;
	}
	printf("Enter Data: ");
	scanf("%d",&val);
	deque[left]=val;
}

void delete_left()
{
	if(left==-1 && right ==-1)
	{
		printf("Underflow\n");
	}
	else if(left==right)
	{
		printf("Deleted Left: %d",deque[left]);
		left=right=-1;
	}
	else 
	{
		printf("Delete Left: %d",deque[left]);
		if(left==max-1)
		left=0;
		else
		left++;
	}
}

void delete_right()
{
	if(left==-1 && right ==-1)
	{
		printf("Underflow\n");
	}
	else if(left==right)
	{
		printf("Deleted Right: %d",deque[right]);
		left=right=-1;
	}
	else
	{
		printf("Delete Right: %d",deque[right]);
		if(right==0)
		right=max-1;
		else
		right--;
	}

}

void display()
{
	int front,rear;
	front=left;
	rear=right;
	if(front==-1 && rear==-1)
	{
		printf("Underflow\n");
	}
	else
	{
		while(front!=rear)
		{
			printf("%d ",deque[front]);
			front=(front+1)%max;
		}
		printf("%d\n",deque[front]);
	}
}

void input_deque()
{
	int ch;
	do
	{
		printf("1.Input Right\n2.Delete Left\n3.Delete Right\n4.Display\n5.Exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: input_right();break;
			case 2: delete_left();break;
			case 3: delete_right();break;
			case 4: display();break;
		}
		printf("\n");
	}while(ch!=5);
}

void output_deque()
{
	int ch;
	do
	{
		printf("1.Input Right\n2.Delete Left\n3.Delete Right\n4.Display\n5.Exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: input_left();break;
			case 2: input_right();break;
			case 3: delete_left();break;
			case 4: display();break;
		}
		printf("\n");
	}while(ch!=5);
}

int main()
{
	int ch;
	printf("1.Input Restricted\n2.Output Restricted: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: input_deque();break;
		case 2: output_deque();break;
	}
}
