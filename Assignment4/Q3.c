#include<stdio.h>
#include<stdlib.h>
struct linklist
{
	int data;
	int priority;
	struct linklist *address;
};

typedef struct linklist node;


void insert(node **h,int val,int p)
{
	node *x,*y;
	if((*h)==NULL)
	{
		(*h)=(node*)malloc(sizeof(node));
		(*h)->data=val;
		(*h)->priority=p;
		(*h)->address=(*h);
	}
	else
	{
		int s=0;
		node *current=*h;
		x=(*h);
		while(current->priority>=p)
		{
			x=current;
			current=current->address;
			s++;
			if(current==(*h))
			break;
		}
		if(current==(*h)&&s>0)
		{
			current=x;
			current->address=(node*)malloc(sizeof(node));
			current->address->data=val;
			current->address->priority=p;
			current->address->address=(*h);
		}
		else
		{
			y=current->address;
			current->address=(node*)malloc(sizeof(node));
			current->address->address=y;
			current->address->data=current->data;
			current->address->priority=current->priority;
			current->data=val;
			current->priority=p;
		}
	}
}


void delete(node **h)
{
	node *current,*x;
	if(*h==NULL)
	printf("error");
	else if((*h)->address!=(*h))
	{
		x=(*h);
		(*h)=(*h)->address;
		current=(*h);
			while(current->address!=x)
			{
				current=current->address;
			}
			current->address=(*h);
	}
	else if((*h)->address==(*h))
	{
		(*h)=NULL;
	}
}


void display(node **h)
{
	if((*h)==NULL)
	printf("Underflow !!");
	else
	{
		node *current=*h;
		do
		{
			printf("Data : %d & its Priority : %d \n",current->data,current->priority);
			current=current->address;
		}while((current->address!=(*h)));
		if(current!=*h)
		printf("Data : %d & its Priority : %d\n",current->data,current->priority);
	}
}


int main()
{
	node *head=NULL;
	char x;
	int val,target,p,s;
	do
	{
	printf("\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 for display\nEnter 4 to Exit");
	scanf("\n%d",&s);
	switch(s)
	{
		case 1:
			printf("Enter number to be inserted and its priority:");
			scanf("%d%d",&val,&p);
			insert(&head,val,p);
			break;
		case 2:
			delete(&head);
			break;
		case 3:
			display(&head);
			break;
		case 4 :
		    break;
	}
	}while(s!=4);
	return 0;
}
