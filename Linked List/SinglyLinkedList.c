#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL;

void create_ll()
{
    struct node *new_node,*ptr;
    char ch;
    do
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter data ");
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(start==NULL)
        start=new_node;
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=new_node;
        }
        fflush(stdin);
        printf("To Enter More press 'y' ");
        scanf("%c",&ch);
    } while (ch=='y'||ch=='Y');
    
}

void display()
{
    struct node * ptr=start;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void insert_beg()
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d",&new_node->data);
    new_node->next=start;
    start=new_node;
}

void insert_end()
{
    struct node *new_node,*ptr;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=new_node;
}

void insert_before()
{
    struct node *preptr,*ptr,*new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    printf("Enter node value ");
    int val;
    scanf("%d",&val);
    preptr=ptr=start;
    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
}

void insert_after()
{
    struct node *preptr,*ptr,*new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    printf("Enter node value ");
    int val;
    scanf("%d",&val);
    preptr=ptr=start;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
}

void delete_beg()
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    printf("Deleted");
}

void delete_end()
{
    struct node *preptr,*ptr;
    preptr=ptr=start;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    printf("Deleted");

}

void delete_node()
{
    struct node *preptr,*ptr;
    int val;
    printf("Enter Value ");
    scanf("%d",&val);
    ptr=start;
    if(ptr->data==val)
    {
        delete_beg();
    }
    else
    {
        while (ptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    printf("Deleted");
}

void delete_after()
{
    int val;
    printf("Enter Value");
    scanf("%d",&val);
    struct node *ptr,*preptr;
    preptr=ptr=start;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
}

void delete_list()
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        delete_beg();
    }
}

void sort_list()
{
    struct node *ptr1,*ptr2;
    ptr1=start;
    while(ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data > ptr2->data)
            {
                int temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    printf("Sorting Done");
}

int main()
{
    int option;
    do
    {
        printf("1.Create\n2.Display\n3.Add Beg\n4.Add End\n5.Add Before Node");
        printf("\n6.Add After Node\n7.Delete Beg\n8.Delete End\n9.Delete Node");
        printf("\n10.Delete After Node\n11.Delete Entire List\n12.Sort List\n13.Exit: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:create_ll();break;
        case 2:display();break;
        case 3:insert_beg();break;
        case 4:insert_end();break;
        case 5:insert_before();break;
        case 6:insert_after();break;
        case 7:delete_beg();break;
        case 8:delete_end();break;
        case 9:delete_node();break;
        case 10:delete_after();break;
        case 11:delete_list();break;
        case 12:sort_list();break;
        }
    } while (option!=13);
    
}