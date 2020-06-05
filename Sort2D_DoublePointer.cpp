#include<stdio.h>
#include<malloc.h>
int ** sort(int ** a,int n)
{
	int i,j,*temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if( (*(a+j)+1) > (*(a+j+1)+1) )
			{
				temp=*(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1)=temp;
			}
		}
	}
	return a;
}
int main()
{
	int **a,n,i,j,c=0;
	printf("Enter size: ");
	scanf("%d",&n);
	a=(int**)calloc(sizeof(int*),n);
	for(i=0;i<n;i++)
	{
		*(a+i)=(int*)calloc(sizeof(int),3);
		for(j=0;j<3;j++)
		{
			*(*(a+i)+j)=++c;
		}
	}
	a=sort(a,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		printf("%d ",*(*(a+i)+j));
		printf("\n");
	}
}
