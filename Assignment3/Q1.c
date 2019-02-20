   #include<stdio.h>
   
   #define SIZE 10
   
    int stackA[SIZE],stackB[SIZE],stackC[SIZE];
   
    int sizeA=0,sizeB=0,sizeC=0;
   
    void Push(int *stack,int n, int *top)
   {
    if((*top)>SIZE)
    printf("Stack Overflow !!\n");
    else
     {
      stack[*top] = n;
      (*top)++;
    }
   }
  
   int Pop(int *stack, int *top)
   {
   if( (*top) <= 0 )
    {
     return -1;
    }
   else
    {
     int x = stack[(*top)-1];
     (*top)--;
     return x;
    }
   }
  
  
   int main()
   {
     int size, j, n, p;
     scanf("%d",&size);
     int z[100];
     for(p = 0; p<100; p++)
      z[p]=0;
  
     for(j = 0; j<size; j++)
     {
     scanf("%d",&n);
     Push( stackA, n, &sizeA);
     }
 
 
     int x;
     while ( sizeA > 0 )
     {
     x = Pop( stackA, &sizeA);
     Push( stackC, x, &sizeC);
     }
 
     while ( sizeC > 0 )
     {
     x = Pop( stackC, &sizeC);
     Push( stackA, x, &sizeA);
     if(z[x]==0)
     {
      Push( stackB, x, &sizeB);
      z[x]=1;
     }
     }
 
    printf("Elements :\n");
   int i=0;
     while(i<sizeB)
     {
      printf("%d ", stackB[i]);
      i++;
     }
 
   printf("\n");
 
   int f=0;
    printf("given stack:\n");
    while(f<sizeA)
     {
       printf("%d ", stackA[f]);
       f++;
      }
   printf("\n");
     return 0;
   }