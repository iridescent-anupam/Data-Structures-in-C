#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char emp;
	int task;
	int time;
	struct node *address;
}Node;


void insert(Node **H,char x,int tk,int t)
{
	Node *y;
	if((*H)==NULL)
	{
		(*H)=(Node*)malloc(sizeof(Node));
		(*H)->emp=x;
		(*H)->time=t;
		(*H)->task=tk;
		(*H)->address=NULL;
	}
	else
	{
		Node *current=*H;
		while(current!=NULL)
		{
			y=current;
			current=current->address;
		}
		current=y;
		current->address=(Node*)malloc(sizeof(Node));
		current->address->emp=x;
		current->address->time=t;
		current->address->task=tk;
		current->address->address=NULL;
	}
}


int calc(Node **H,char start)
{
	Node *current=*H,*x=*H;
	int tinst=0;
	while(current->emp!=start)
	{
		x=current;
		current=current->address;
	}
	while(*H!=NULL)
	{
		if(current->time<=2)
		{
			if(current==(*H))
			{
				printf("%c\t%d\t%d\n",current->emp,tinst,tinst+current->time);
				tinst=tinst+current->time;
			    (*H)=current->address;
				current=current->address;
			}
			else
			{
			  x->address=current->address;
			  printf("%c\t%d\t%d\n",current->emp,tinst,tinst+current->time);
			  tinst=tinst+current->time;
			  current=x->address;
			}
		}
		else
		{
		    printf("%c\t%d\t%d\n",current->emp,tinst,tinst+2);
		    x=current;
		    tinst=tinst+2;
		    current->time=current->time-2;
		    current=current->address;
		}
		if(current==NULL)
		current=(*H);
	}
}


int display(Node **H)
{
	Node *current=*H;
	while(current!=NULL)
	{
		printf("%c %d %d\n",current->emp,current->task,current->time);
		current=current->address;
	}
	return 0;
}


int main()
{
	Node *H=NULL;
	int i,n,task,time;
	char name,start;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %dth employee name,task & time interval :",i);
		scanf(" %c%d%d",&name,&task,&time);
		insert(&H,name,task,time);
	}
	printf("Enter the starting employee :");
	scanf(" %c",&start);
	printf("Emp\tStart\tEnd\n");
	calc(&H,start);
	return 0;
}
