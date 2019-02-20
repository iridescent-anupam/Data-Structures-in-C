#include<stdio.h>
  #include<string.h>
  #include<ctype.h>
  #define size 15
   //Evaluating postfix expression.
  
  void PUSH(int *s,int *t, int a)
  {
   if(*t==size-1)
   {
    printf("Stack overflow !!");
   }
   else
   {
    (*t)++;
    s[*t]=a;
   }
  }
  
  
  int POP(int *s,int *t)
  {
   if(*t==-1)
   {
    printf("Stack underflow !!");
    return 0;
   }
   else
   {
    return s[(*t)--];
   }
  }
  
  
  int main()
   {
      int top=-1;
      int i=0;
      int v1=0,v2=0;
      int stack[size];
      char postfix[size];
      int res=0;
      printf("\nEnter a postfix expression\n");
      scanf("%s", postfix);
       //strcpy(postfix,argv[1]);
      for(i=0;i<strlen(postfix);i++)
       {
         if(isdigit(postfix[i]))
         {
          PUSH(stack,&top,postfix[i]-48);
         }
         else
         {
          v1=POP(stack,&top);
          v2=POP(stack,&top);
          switch(postfix[i])
          {
            case '*':
                    res= v1 * v2;
                   break;
            case '/':
                   res= v2 / v1;
                  break;
           case '+':
                    res= v1 + v2;
                   break;
            case '-':
                    res= v2 - v1;
                   break;
           }
           PUSH(stack,&top,res);
          }
         }
        printf("\n RESULT: \n %d \n", stack[top]);
        return 0;
    }
