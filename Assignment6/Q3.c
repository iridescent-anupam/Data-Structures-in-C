#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int POP(int *s,int *t);
int PUSH(int *s,int *t,int val);
void create(int *a,int i,int j,int *l,int *r);
void inor(int *a,int *l,int *r,int i);

int main()
{
    int a[SIZE],LC[SIZE],RC[SIZE],n,i,j=0;
    printf("Enter the limit of inputs : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    for(i=0;i<100;i++)
      {
         LC[i] = -1;
         RC[i] = -1;
      }
    for(i=0;i<n;i++)
       create(a,i,j,LC,RC);
     printf("Data\t LC\t RC\n"); 
    for(i=0;i<n;i++)
       printf("%d\t %d\t %d\n",a[i],LC[i],RC[i]);
    printf("\n");
    inor(a,LC,RC,0);  
          
}


void create(int *a,int i,int j,int *l,int *r)
{
    if(i>0)
    {
        if(l[j]==-1&&(a[i]<a[j]))
                 l[j] = i;
        else if(r[j]==-1&&(a[i]>a[j]))
               r[j] = i;
        else
          {
              if(a[i]<a[j])
                create(a,i,l[j],l,r);
              else if(a[i]>a[j])
              create(a,i,r[j],l,r); 
          } 
    }
}


void inor(int *a,int *l,int *r,int i)
{
    int stack[100],top=-1,m,j=0,k,d=0;
    while(d!=1)
    {
        if(i!=-1)
        {
            PUSH(stack,&top,a[i]);
            i = l[i];
        }
        else
           {
               if(top!=-1)
                  {
                      k = POP(stack,&top);
                      j = 0;
                      while(a[j]!=k)
                         j++;
                      printf("%d was popped \n",a[j]);
                    i = r[j];    
                  }
              else
               d = 1;           
           }
    }
   
}


int PUSH(int *s,int *t,int val)
{
    if((*t)==(SIZE-1))
    {
        printf("\nStack Overflow !!");
    }
    else
    {
        (*t)++;
        s[*t] = val;
    }
}


int POP(int *s,int *t)
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
        return r;
    }
   
}
