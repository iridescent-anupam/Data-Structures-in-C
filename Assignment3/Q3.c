 #include<stdio.h>
 #include<stdlib.h>
 
 void PUSH1(int* s,int* top,int value);
 void PUSH2(int* s,int* top,int value);
 void PUSH3(int* s,int* top,int value);
 int POP1(int *s,int* top);
 int POP2(int *s,int* top);
 int POP3(int *s,int* top);
 
 int main(void)
 {
  int stack_major[15],top1=0,top2=5,top3=10,i;
  int ch=0,value;
 
  while(ch!=4)
  {
   printf("Which stack would you want to operate 1,2,3 ?\n");
   scanf("%d",&ch);
 
   switch(ch)
   {
    case 1: {
             int p=0;
             printf("For PUSH press 1 and for POP press 2\n");
             scanf("%d",&p);
             switch(p)
             {
              case 1:
                   printf("Enter the value\n");
                   scanf("%d",&value);
                   PUSH1(stack_major,&top1,value);
                  break;
 
              case 2:
                   POP1(stack_major,&top1);
                  break;
             }
             }
             break;
 
 
    case 2: {
             int p=0;
             printf("for PUSH press 1 for POP press 2\n");
             scanf("%d",&p);
             switch(p)
             {
              case 1:
                   printf("enter the value\n");
                   scanf("%d",&value);
                   PUSH2(stack_major,&top2,value);
                  break;
 
             case 2:
                   POP2(stack_major,&top2);
                  break;
             }
             }
             break;
 
 
 
    case 3:  {
             int p=0;
             printf("for PUSH press 1 for POP press 2\n");
             scanf("%d",&p);
             switch(p)
             {
             case 1:
                   printf("enter the value\n");
                   scanf("%d",&value);
                   PUSH3(stack_major,&top3,value);
                  break;
             case 2:
                  POP3(stack_major,&top3);
                 break;
             }
             }break;
 
    }
  printf("do you want to quit? press 4\n");
  scanf("%d",&ch);
 
  }
   for( i=0;i<5;i++)
    {
     printf(" %d ",stack_major[i]);
    printf(" ");
    }
     printf("\n");
    for( i=5;i<10;i++)
    {
     printf(" %d ",stack_major[i]);
     printf(" ");
    }
     printf("\n");
     for( i=10;i<15;i++)
      {
       printf(" %d ",stack_major[i]);
       printf(" ");
      }
       printf("\n");
 }
 
 
 void PUSH1(int* s,int* top,int value)
 {
  if(*top==4)
  printf("stack1 overflow");
  else
  {
   s[*top]=value;
   (*top)++;
  }
 }
 
 void PUSH2(int* s,int* top,int value)
 {
  if(*top==9)
  printf("stack1 overflow");
  else
  {
   s[*top]=value;
   (*top)++;
  }
 }
 
 void PUSH3(int* s,int* top,int value)
 {
  if(*top==14)
  printf("stack1 overflow");
  else
  {
   s[*top]=value;
   (*top)++;
  }
 }
 
 int POP1(int *s,int* top)
 {
  if(*top==0)
  printf("stack1 underflow");
  else
  {
   int r=s[*top];
   return r;
  }
 }

 
 int POP2(int *s,int* top)
 {
  if(*top==5)
  printf("stack1 underflow");
  else
  {
   int r=s[*top];
   return r;
  }
 }
 
 int POP3(int *s,int* top)
 {
  if(*top==10)
  printf("stack1 underflow");
  else
  {
   int r=s[*top];
   return r;
  }
 }
