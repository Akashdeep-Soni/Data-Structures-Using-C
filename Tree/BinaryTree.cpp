#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};

struct node *create(struct node *root)
{
	int val;
	struct node *new_node;
	printf("Enter Value: ");
	scanf("%d",&val);
	if(val==-1)
	{
		return NULL;
	}
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=val;
	printf("Enter left node of %d: ",val);
	new_node->left=create(root);
	printf("Enter right node of %d: ",val);
	new_node->right=create(root);
	return new_node;
}

void preorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void postorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

int main()
{
	struct node *root=NULL;
	root=create(root);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}
