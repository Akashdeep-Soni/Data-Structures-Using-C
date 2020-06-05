#include<stdio.h>
#define max 4
int queue[max];
int frontA=-1,rearA=-1;
int frontB=max,rearB=max;

void insertA(int val)
{
	if(rearA+1==rearB)
	{
		printf("Overflow\n");
	}
	else
	{
		if(frontA==-1 && rearA==-1)
		{
			frontA=rearA=0;
		}
		else
		{
			rearA++;
		}
		queue[rearA]=val;
	}
}

void insertB(int val)
{
	if(rearB-1==rearA)
	{
		printf("Overflow\n");
	}
	else
	{
		if(frontB==max && rearB==max)
		{
			frontB=rearB=max-1;
		}
		else
		{
			rearB--;
		}
		queue[rearB]=val;
	}
}

int deleteA()
{
	int val=-1;
	if(frontA==-1 && rearA==-1)
	{
		printf("Underflow\n");
	}
	else if(frontA==rearA)
	{
		val=queue[frontA];
		frontA=rearA=-1;
	}
	else
	{
		val=queue[frontA];
		frontA++;
	}
	return val;
}

int deleteB()
{
	int val=-1;
	if(frontB==max && rearB==max)
	{
		printf("Underflow\n");
	}
	else if(frontB==rearB)
	{
		val=queue[frontB];
		frontB=rearB=max;
	}
	else
	{
		val=queue[frontB];
		frontB--;
	}
	return val;
}

void displayA()
{
	int i;
	if(frontA==-1 && rearA==-1)
	{
		printf("Underflow\n");
	}
	else
	for(i=frontA;i<=rearA;i++)
	{
		printf("%d ",queue[i]);
	}
}

void displayB()
{
	int i;
	if(frontB==max && rearB==max)
	{
		printf("Underflow\n");
	}
	else
	for(i=frontB;i>=rearB;i--)
	{
		printf("%d ",queue[i]);
	}
}

int main()
{
	int ch,val;
	do
	{
		printf("1.Insert A\n2.Insert B\n3.Delete A\n4.Delete B\n5.Display A\n6.Display B\n7.Exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter Data: ");
				scanf("%d",&val);
				insertA(val);
				break;
			case 2:
				printf("Enter Data: ");
				scanf("%d",&val);
				insertB(val);
				break;
			case 3:
				val=deleteA();
				if(val!=-1)
				printf("Deleted Value: %d\n",val);
				break;
			case 4:
				val=deleteB();
				if(val!=-1)
				printf("Deleted Value: %d\n",val);
				break;
			case 5:
				displayA();
				printf("\n");
				break;
			case 6:
				displayB();
				printf("\n");
				break;
				
		}
	}while(ch!=7);
}
