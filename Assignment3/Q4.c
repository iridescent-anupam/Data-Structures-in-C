#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 100

void push(int *stack,int *top,int value)
{
	if(*top==SIZE-1)
	{
		printf("Stack Overflow !!");
	}
	else
	{
		(*top)++;
		stack[*top]=value;
	}
}
int pop(int *stack,int *top)
{
	int x;
	if(*top==-1)
	{
		printf("Stack Underflow !!");
	}
	else
    {
       x=stack[*top];
	   (*top)--;
	   return x;
	}
}
int main()
{
	int i,j,k,n,m,p,top1=-1,top2=0,top3=-1,a[1000],b[100],c[100];
	printf("Enter size of each stack=");
	scanf("%d%d%d",&n,&m,&p);
	top1=-1,top2=n-1,top3=n+m-1;
	for(i=0;i<n+m+p;i++)
	{
		scanf("%d",&j);
		if(top1<n&&i<n)
		push(a,&top1,j);
		if(top2<n+m&&i>=n&&i<n+m)
		push(a,&top2,j);
		if(top3<n+m+p&&i>=n+m&&i<n+m+p)
		push(a,&top3,j);
	}
	top1=-1,top2=-1;
	push(b,&top2,pop(a,&top3));
	int count=0;
	for(i=1;i<n+m+p;i++)
	{
		push(c,&top1,pop(a,&top3));
		if(b[top2]<c[top1])
		{
			push(b,&top2,pop(c,&top1));
		}
		else
		{
			for(j=top2;j>=0;j--)
			{
				push(a,&top3,pop(b,&top2));
				count++;
				if(b[top2]<c[top1]||top2==-1)
				{
					push(b,&top2,pop(c,&top1));
					break;
				}

			}

			for(j=0;j<count;j++)
			{
				push(b,&top2,pop(a,&top3));
			}
			count=0;
		}
	}
	for(i=0;i<n+m+p;i++)
	{
		printf("%d ",b[i]);
	}



}
