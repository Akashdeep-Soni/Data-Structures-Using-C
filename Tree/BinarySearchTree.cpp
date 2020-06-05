#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};

struct node *create_node(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=temp->right=NULL;
	return temp;
}

struct node *insert_element(struct node *root,int val)
{
	if(root==NULL)
	{
		root=create_node(val);
		return root;
	}
	else if(val < root->data)
	{
		root->left=insert_element(root->left,val);
	}
	else
	{
		root->right=insert_element(root->right,val);
	}
	return root;
}

void preorder_traversal(struct node *root)
{
	if(root==NULL)
	return;
	printf("%d ",root->data);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void inorder_traversal(struct node *root)
{
	if(root!=NULL)
	{
		inorder_traversal(root->left);
		printf("%d ",root->data);
		inorder_traversal(root->right);
	}
	// if root==NULL control will be returned
}

void postorder_traversal(struct node *root)
{
	if(root==NULL)
	return;
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%d ",root->data);
}

struct node *find_smallest(struct node *root)
{
	if(root==NULL || root->left==NULL)
	return root;
	else
	return find_smallest(root->left);
}

int find_largest(struct node *root)
{
	if(root->right==NULL)
	return root->data;
	else
	return find_largest(root->right);
}

int search_val(struct node *root,int val)
{
	if(root==NULL)
	return 0;
	else if(root->data == val)
	return 1;
	else if(val < root->data)
	return search_val(root->left,val);
	else
	return search_val(root->right,val);
}

struct node *delete_val(struct node *root,int val)
{
	if(root==NULL)
	return NULL;
	else if(val < root->data)
	root->left = delete_val(root->left,val);
	else if(val > root->data)
	root->right = delete_val(root->right,val);
	else // root to be deleled found
	{
		// No child
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		// One child
		else if(root->left!=NULL && root->right==NULL)
		{
			struct node *temp;
			temp=root;
			root=root->left;
			free(temp);
		}
		else if(root->right!=NULL && root->left==NULL)
		{
			struct node *temp;
			temp=root;
			root=root->right;
			free(temp);
			
		}
		// Two child
		else
		{
			struct node *temp=find_smallest(root->right);
			root->data=temp->data;
			root->right=delete_val(root->right,temp->data);
		}
	}
	return root;
}

int count_nodes(struct node *root)
{
	if(root==NULL)
	return 0;
	else
	return count_nodes(root->left)+count_nodes(root->right)+1;
}

int count_internal(struct node *root)
{
	if(root==NULL)
	return 0;
	else if(root->left==NULL && root->right==NULL)
	return 0;
	else
	return count_internal(root->left)+count_internal(root->right)+1;
}

int count_external(struct node *root)
{
	if(root==NULL)
	return 0;
	else if(root->left==NULL || root->right==NULL)
	return 1;
	else
	return count_external(root->left) + count_external(root->right);
}

int find_height(struct node *root)
{
	if(root==NULL)
	return -1;
	else
	{
		int leftheight=find_height(root->left);
		int rightheight=find_height(root->right);
		if(leftheight > rightheight)
		return leftheight+1;
		else
		return rightheight+1;
	}
}

void mirror_image(struct node *root)
{
	if(root!=NULL)
	{
		mirror_image(root->left);
		mirror_image(root->right);
		struct node *temp;
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}

void delete_tree(struct node *root)
{
	if(root==NULL)
	return;
	delete_tree(root->left);
	delete_tree(root->right);
	free(root);
}

int main()
{
	struct node *root=NULL,*temp;
	int ch,val;
	do
	{
		printf("Enter Choice\n1.Insert Element\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Find Smallest\n6.Find Largest\n7.Search Element\n8.Delete Element\n9.Count Nodes\n10.Count Internal Nodes\n11.Count External Nodes\n12.Determine Height\n13.Find Mirror Image\n14.Delete Tree\n15.Exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter Value: ");
				scanf("%d",&val);
				root=insert_element(root,val);
				break;
			case 2:
				printf("Preorder Traversal\n");
				preorder_traversal(root);
				break;
			case 3:
				printf("Inorder Traversal\n");
				inorder_traversal(root);
				break;
			case 4:
				printf("Postorder Traversal\n");
				postorder_traversal(root);
				break;
			case 5:
				temp=find_smallest(root);
				printf("Smallest Number %d\n",temp->data);
				break;
			case 6:
				val=find_largest(root);
				printf("Largest Number %d\n",val);
				break;
			case 7:
				printf("Enter Value: ");
				scanf("%d",&val);
				if(search_val(root,val)==1)
				printf("%d Exist\n",val);
				else
				printf("%d Not Exist\n",val);
				break;
			case 8:
				printf("Enter Value: ");
				scanf("%d",&val);
				root=delete_val(root,val);
				break;		
			case 9:
				val=count_nodes(root);
				printf("Total Nodes: %d\n",val);
				break;
			case 10:
				val=count_internal(root);
				printf("Total Internal Nodes: %d\n",val);
				break;
			case 11:
				val=count_external(root);
				printf("Total External Nodes: %d\n",val);
				break;
			case 12:
				val=find_height(root);
				printf("Tree Height %d",val);
				break;
			case 13:
				mirror_image(root);
				break;
			case 14:
				delete_tree(root);
				root=NULL;
				break;
		}
		printf("\n");
	}while(ch!=15);
}
