#include<stdio.h>
#define size 30

int PUSH(int *s,int *t,int val);
void POP(int *s,int *t);
void dis(int *q,int f,int c);
void inst(int *q,int *r,int *c,int val);
void delt(int *q,int *f,int *c);


int main(void)
{
	int n,k;
	scanf("%d",&n);
	int queue1[size],rear1=-1,front1=0,count1=0,queue2[size],rear2=-1,front2=0,count2=0,i=0,stack[size],top=-1;
	for(i=1;i<=n;i++)
	inst(queue1,&rear1,&count1,i);
	for(i=1;i<=n;i++)
	{
	scanf("%d",&k);
	inst(queue2,&rear2,&count2,k);
    }
	
	while(count1!=0)
	{
	int e;
	e = queue1[front1];
	delt(queue1,&front1,&count1);
	if(e==queue2[front2])
	{
	 delt(queue2,&front2,&count2);
	 while(top!=-1)
	 {
	 if(stack[top]==queue2[front2])
	 {
	  POP(stack,&top);
	  delt(queue2,&front2,&count2);
	 }
	 else 
	 break;
	 }
	}
	else
	PUSH(stack,&top,e);	  
	}
	if(count1==0&&count2==0)
	  printf("yes");
	else
	  printf("no");  
}


void dis(int *q,int f,int c)
{
	int i=0;
	if(c==0)
	{
	 printf(" \nError, no element in queue !!");
	}
	else
	{
	for(i=f;c>0;(i=i+1)%size,c--)
	printf("%d ",q[i]);	
	}
}


void inst(int *q,int *r,int *c,int val)
{
	if(*c == size)
	{
	 printf("\n overflow");
	}
	else
	{
	 *r = ((*r)+1)%size;
	 q[*r] = val;
	 (*c)++;
	}
}


void delt(int *q,int *f,int *c)
{
	if(*c == 0)
	{
		printf("\n Underflow !!");
	}
	else
	{
	 *f= ((*f)+1)%size;
	 (*c)--;
	}
}


int PUSH(int *s,int *t,int val)
{
	if((*t)==(size-1))
	{
	 printf("\nStack overflow !!");
	}
	else
	{
	 (*t)++;
	 s[*t] = val;
	}
}


void POP(int *s,int *t)
{
	int r;
    if((*t)==-1)
    {
     printf("\nStack Underflow !!");
	}
	else
	{
	 r = s[*t];
	 (*t)--;
	}
	
}    
