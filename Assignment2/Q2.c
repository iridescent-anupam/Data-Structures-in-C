#include<stdio.h>

int main()

{
 int n,i,t;
 printf("Enter the value of n :");
 scanf("%d",&n);
 int a[n];
 printf("Enter the numbers : \n");
 for(int i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }

for(i=0;i<n/2;i++)
 {
  t=a[i];
  a[i]=a[n-i-1];
  a[n-i-1]=t;
 }

 for(int i=0;i<n;i++)
  printf("%d ",a[i]);

return 0;
}
