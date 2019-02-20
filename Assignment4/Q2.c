#include <stdio.h>
#include <stdlib.h>

void push1(int);
void push2(int);

int pop1();
int pop2();

void Insert();
void Delete();
void Display();

 
int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;

void main()
{
  int ch;
  printf("\n1 - Insert element into queue");
  printf("\n2 - Delete element from queue");
  printf("\n3 - Display from queue");
  printf("\n4 - Exit");
  top1 = -1, top2 = -1;

  while (1)
  {
   printf("\nEnter your choice : ");
   scanf("%d", &ch);
   switch (ch)
        {
         case 1: Insert();
                 break;

         case 2: Delete();
                 break;

         case 3: Display();
                 break;

         case 4: exit(0);

        default:
            printf("Wrong choice !!");
        }

    }

}


void push1(int data)                             //Function to push the element on to the stack 1
{
 st1[++top1] = data;
}


int pop1()                                       //Function to pop the element from the stack 1
{
return(st1[top1--]);
}


void push2(int data)                              //Function to push an element on to stack 2
{
st2[++top2] = data;
}

 
int pop2()                                        //Function to pop an element from stack 2
{
 return(st2[top2--]);
}
 

void Insert()                                     //Function to add an element into the queue using stack
{
    int data, i;
    printf("Enter data into queue : ");
    scanf("%d", &data);
    push1(data);
    count++;
}
 

void Delete()                                      //Function to delete an element from the queue using stack
{
    int i;
    for (i = 0;i <= count;i++)
    {
     push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
     push1(pop2());
    }
}
 

void Display()                                          //Function to display the elements in the stack
{
    int i;
    for (i = 0;i <= top1;i++)
    {
     printf(" %d ", st1[i]);
    }
}
