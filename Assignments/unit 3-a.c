#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *createnode(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void insertAtBeginning(int value)
{
    struct node *newnode=createnode(value);
    newnode->next=head;
    head=newnode;
}
void insertAtEnd(int value){
    struct node *newnode=createnode(value);
    if(head==NULL)
        head=newnode;
    else{
        struct node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}
void deletevalue(int value)
{
    struct node *temp=head,*prev=NULL;
    while(temp && temp->data != value)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Roll no %d not found\n",value);
        return;
    }
    if(prev==NULL)
        head=temp->next;
    free(temp);
    printf("Deleted %d from list\n",value);
}
void search(int value)
{
    struct node *temp=head;
    int pos=1;
    while(temp)
    {
        if(temp->data==value)
        {
            printf("roll no %d found at position %d\n",value,pos);
            return;
        }
        temp=temp->next;
        pos++;
    }
    printf("roll no %d not found\n",value);
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp=head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf(NULL);
}
int main()
{
    int ch,value,key;
    while(1)
    {
        printf("\nMenu:\n1.Insert at beginning\n2.Insert at end\n3.Delete\n4.Search\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter roll no: ");
            scanf("%d",&value);
            insertAtBeginning(value);
            break;
            case 2:printf("Enter roll no: ");
            scanf("%d",&value);
            insertAtEnd(value);
            break;
            case 3:printf("Enter roll no: ");
            scanf("%d",&value);
            deletevalue(value);
            break;
            case 4:printf("Enter roll no: ");
            scanf("%d",&value);
            search(value);
            break;
            case 5:display();
            break;
            case 6:exit(0);
            default:printf("invalid choice\n");
        }
    }
    return 0;
}