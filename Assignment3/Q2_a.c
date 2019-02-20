#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define SIZE 20
   
   char POP();
   void PUSH(char );
   int priority(char );
   
 char infix[SIZE],postfix[SIZE],stack[SIZE],top=-1,i,j=0;
 
 int main(int argc,char *argv[])
 {
  strcpy(infix,argv[1]);
  for(i=0;i<strlen(infix);i++)
  {
   if(isdigit(infix[i]))
    postfix[j++]=infix[i];
   else
   {
    switch(infix[i])
     {
      case '(': PUSH(infix[i]);
                 break;
 
      case ')': do
                  {
                   postfix[j++]=POP();
                  } while((stack[top]!='('));
                break;
 
      default : if((priority(infix[i])<=priority(stack[top]))&&(top!=-1))
                 {
                  do
                    {
                     postfix[j++]=POP();
                    } while((priority(infix[i])<=priority(stack[top]))&&(top!=-1));
 
                 PUSH(infix[i]);
                 }
 
                else
                 PUSH(infix[i]);
     }
 
   }
 
   if(infix[i]==')')
    POP();
  }
 
  do
   {
    postfix[j++]=POP();
   } while(top!=-1);
 
  printf("Postfix conversion is : %s\n",postfix);
  return 0;
  }
 
  void PUSH(char val)
  {
   if(top>=SIZE)
    printf("Stack Overflow");
   else
    {
     top++;
     stack[top]=val;
    }
   }
 
  char POP()
  {
   if(top<=-1)
   {
    printf("Stack is Empty");
    return '\0';
   }
   else
   {
    char r=stack[top];
    top--;
    return r;
   }
  }
 
  int priority(char ch)
  {
   switch(ch)
   {
   case '/': return 5;
             break;
   case '*': return 4;
             break;
   case '+': return 3;
             break;
   case '-': return 2;
             break;
   case '(': return 1;
             break;
   }
  }
