#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

typedef struct Node
{
	int val,row,column;
	struct Node *next;
}Node;


void create(Node **H,int element,int row_index,int column_index)     //This creates a new node and adds a non zero value to it
{
    Node *temp,*r;
    temp=*H;
	if(temp==NULL)
	{
        temp=(Node*)malloc(sizeof(Node));
        temp->val=element;
        temp->row=row_index;
        temp->column=column_index;
        temp->next=NULL;
        *H=temp;
   	}
   	else
   	{
   		while(temp->next != NULL)
   			temp=temp->next;

   		r=(Node*)malloc(sizeof(Node));
        r->val=element;
        r->row=row_index;
        r->column=column_index;
        r->next=NULL;
        temp->next = r;
   	}	
}

void display(Node **H)    //Displays the Matrix
{
    Node *temp,*r,*s;
    temp=r=s=*H;
 
    printf("Row Position: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->row);
        temp=temp->next;
    }
    printf("\n");
 
    printf("Column Position: ");
    while(r!=NULL)
    {
        printf("%d ",r->column);
        r=r->next;
    }
    printf("\n");
    
    printf("Value: ");
    while(s!=NULL)
    {
        printf("%d ",s->val);
        s=s->next;
    }
    printf("\n");
}

int main()
{
	int i,j;
	int A[SIZE][SIZE];
	printf("Enter a Sparse Matrix : \n");
	for(i=0;i<SIZE;i++)
		{
		for(j=0;j<SIZE;j++)
	     {
	     scanf("%d",&A[i][j]);
	     }
		}

    Node *H=NULL;
    
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(A[i][j] != 0)              //Only Non zero values are added to the nodes
            create(&H,A[i][j],i,j);
        }    
    }
 
    display(&H);
 
    return 0;
}


