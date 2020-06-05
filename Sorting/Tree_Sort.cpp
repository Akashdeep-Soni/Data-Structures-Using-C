#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};

struct node* create_node(int val)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->left=ptr->right=NULL;
	return ptr;
}

struct node* insert_node(struct node *root,int val)
{
	if(root==NULL)
	{
		root=create_node(val);
		return root;
	}
	else if(root->data > val)
	{
		root->left=insert_node(root->left,val);
	}
	else
	{
		root->right=insert_node(root->right,val);
	}
}

void inorder_traversal(struct node *root)
{
	if(root==NULL)
	return;
	inorder_traversal(root->left);
	printf("%d ",root->data);
	inorder_traversal(root->right);
}

void tree_sort(int a[],int n)
{
	int i;
	struct node *root=NULL;
	for(i=0;i<n;i++)
	root=insert_node(root,a[i]);
	//Inorder Traversal (Sorted in accending order)
	inorder_traversal(root);
}

int main()
{
	int i,n,a[10];
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf("Sorted Array\n");
	tree_sort(a,n);
}
