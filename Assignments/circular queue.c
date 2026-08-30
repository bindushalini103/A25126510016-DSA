#include<stdio.h>
int front=-1;
int rear=-1;
void insert(int value,int size,int queue[])
{
	if((rear+1)%size==front){
	printf("Queue overflow.\n");
	return;
}
	if(front==-1)
	front=0;
	rear=(rear+1)%size;
	queue[rear]=value;
	printf("Value %d is inserted.\n",value);
}
void deletevalue(int size,int queue[])
{
	if(front==-1)
	printf("Queue underflow.\n"); 
	int value=queue[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	front=(front+1)%size;
	printf("Value %d is deleted.\n",value);
}
void display(int size,int queue[])
{
	if(front==-1)
	printf("Queue underflow.\n");
	printf("Queue elements: \n");
	int i=front;
	while(1)
	{
		printf("%d ",queue[i]);
		if(i==rear)
		break;
		i=(i+1)%size;
	}
	printf("\n");
}
int main()
{
	int size;
	printf("Enter the size of circular queue:");
	scanf("%d",&size);
	
	int queue[size];
	int front=-1;
	int rear=-1;
	int choice,value;
	while(1)
	{
		printf("\n-----Circular queue operations-----\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:printf("Enter value:");
			scanf("%d",&value);
			insert(value,size,queue);
			break;

			case 2:deletevalue(size,queue);
			break;

			case 3:display(size,queue);
			break;

			case 4:printf("Exit.");
			default:
				printf("Invalid input");
		}
	}
	return 0;
}