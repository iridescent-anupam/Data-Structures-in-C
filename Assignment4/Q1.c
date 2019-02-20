#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 5

void display();
void insert(int val);
void delete();
int Queue[SIZE],front=-1,rear=-1;   //Declaring the Circular Queue


int main(void)
{
  int s,val;
  do
  {
  printf("Enter your choice -\n1.)Insert\n2.)Delete\n3.)Display\n4.)Exit\n");
  scanf("%d",&s);
   switch(s)
   {
    case 1 : printf("Enter the value to be Inserted : ");
             scanf("%d",&val);
		         insert(val);
		         break;
    case 2 : delete();
             break;
    case 3 : display();
             break;
    case 4 : break;
    default : printf("Please Enter a Valid Option !!\n");
   }
  }while(s!=4);
 return 0;
}


void insert(int val)                                //Insertion Function for the Circular Queue
{
 if((front==0 && rear==SIZE-1) || (front==rear+1))
  printf("The Circular Queue is Full !!\n");
 else
 {
 if (front == -1)
  {
	front = 0;
	rear = 0;
  }
 else
  {
	if(rear == SIZE-1)
	rear = 0;
	else
	rear = rear+1;
  }
  Queue[rear] = val ;

 }
}


void delete()                                       //Deletion Function for the Circular Queue
{
 if (front == -1)
  {
	printf("Queue Underflow\n");
	return ;
  }
	printf("Element deleted from queue is : %d\n",Queue[front]);
	if(front == rear)
	{
	 front = -1;
	 rear=-1;
	}
	else
	{	
	 if(front == SIZE-1)
	 front = 0;
	 else
	 front = front+1;
	}
}	


void display()                                         //Display Funtion for the Circular Queue
{
 int i;
 if(front==0 && rear==-1)
  printf("The Circular Queue is Empty, so Nothing can be displayed !!");
 else
 {
  if(front>rear)
  {
   for(i=front;i<=SIZE-1;i++)
    printf("\n%d ",Queue[i]);
   for(i=0;i<=rear;i++)
    printf("\n%d ",Queue[i]);
   printf("\nThe Front element is : %d\n",Queue[front]);
   printf("\nThe Rear element is : %d\n",Queue[rear]);
  }
  else
  {
  for(i=front;i<=rear;i++)
   printf("\n%d ",Queue[i]);
  }
  printf("\n");
 }
} 
