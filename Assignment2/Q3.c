#include<stdio.h>
#include<string.h>
int main()
{
 int l,flag=0;
 char A[100];
 char *t,*q;
 printf("Enter the word :");
 scanf("%s",A);
 l=strlen(A);
 t=&A[l-1];
 q=A;
 
 while(q<=t)
 {
  if(*q==*t)
  {
   q++;
   t--;
  }
  else
  {
   flag=1;
   break;
  }
 }
 
 if(flag==0)
 printf("The given word is a Palindrome");
 else
 printf("The given word is not a Palindrome");

 return 0;
 }

 

