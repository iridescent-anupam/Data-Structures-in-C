#include<stdio.h>
#include<math.h>
double binarytodecimal(double n);
int decimaltobinary(int m);

int main()
{
 double n;
 printf("\nEnter a Binary number : ");
 scanf("%lf",&n);
 printf("\nThe Decimal conversion is : %lf",binarytodecimal(n));
 int m;
 printf("\nEnter a Decimal number : ");
 scanf("%d",&m);
 printf("\nThe Binary conversion is : %d",decimaltobinary(m));
 return 0;
}
 
double binarytodecimal(double n)
{
 double dec=0.0,i,inc=0.0;
 double temp;
 temp=n;
 while(temp!=0)
 {
  i=(int)temp%10;
  dec=dec+(i*pow(2,inc));
  temp=temp/10.0;
  inc++;
 }
 return dec;
}

int decimaltobinary(int m)
{
 int temp,i,j=1,binary=0;
 temp=m;
 while(temp!=0)
 {
  i=temp%2;
  binary=binary+(i*j);
  temp=temp/2;
  j=j*10;
 }
 return binary;
}
