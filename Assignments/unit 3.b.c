#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *createnode(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insert(int value)
{
    struct node *newnode=createnode(value);
    if(head==NULL)
        head=newnode;
    else
    {
        struct node *temp=head;
        while(temp->next != NULL)
            {
                temp=temp->next;
            }
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void moveforward(){
    if(head==NULL)
    {
        printf("No pages available\n");
        return;
    }
    struct node *temp=head;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
    printf("\nMoved forward to pagenumber:%d\n",temp->data);
}
void movebackward()
{    if(head==NULL)
    {
        printf("No pages available\n");
        return;
    }
    struct node *temp=head;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            while(temp->prev != NULL)
            {
                temp=temp->prev;
            }
         printf("Moved backward to pagenumber:%d\n",temp->data);
}
void deletepage(int value)
{
    struct node *temp=head;
    while(temp != NULL && temp->data != value)
        {
            temp=temp->next;
        }
    if(temp==NULL)
       {
        printf("page number %d not found\n",value);
        return;
       }
    if(temp->prev != NULL)
        temp->prev->next=temp->next;
    else{
        head=temp->next;
    }
    if(temp->next != NULL)
        temp->next->prev=temp->prev;
    free(temp);
    printf("page number %d deleted from the list\n",value);
    }
void displayfront()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("No pages to display\n");
        return;
    }
    printf("pages from first to last: \n");
    while(temp !=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
}
void displayreverse()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("No pages to display\n");
        return;
    }
    while(temp->next != NULL)
        {
            temp=temp->next;
        }
    printf("\npages from last to first: ");
    while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->prev;
        }
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    displayfront();
    moveforward();
    movebackward();
    deletepage(2);
    displayfront();
    displayreverse();
    return 0;
}