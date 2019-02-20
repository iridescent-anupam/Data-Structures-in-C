#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 7

typedef struct tree
{
    char data[20];  
    struct tree *LC;
    struct tree *RC;  
}BST;

void Create(BST **r,char *in);
void Inorder(BST *r);

int main()
{
    char input[20];
    int f=0;
    BST *R=NULL;
   
    do
    {
        printf("Enter the word : ");
        scanf("%s",input);
       
        Create(&R,input);
       
        f++;
    }
        while(f<=MAX);
       
        Inorder(R);
    return 0;
}

void Create(BST **r,char *in) 
{
    if(*r==NULL)
    {
        *r=(BST *)malloc(sizeof(BST));
        strcpy((*r)->data,in);
        (*r)->LC=NULL;
        (*r)->RC=NULL;
    }
   
    else
    {
    BST *current; 
    current=*r;
    int f=0;

    do
    {   
       if(strcmp((current->data),in)<0)
       {
        if(current->RC==NULL)
        {
        current->RC=(BST *)malloc(sizeof(BST));
        strcpy(current->RC->data,in);
        current->RC->LC=NULL;
        current->RC->RC=NULL;
        f=1;
        }
        current=current->RC;
       
    }
   
    else if(strcmp((current->data),in)>0)
    {
        if(current->LC==NULL)
        {
        current->LC=(BST *)malloc(sizeof(BST));
        strcpy(current->LC->data,in);
        current->LC->LC=NULL;
        current->LC->RC=NULL;
        f=1;
        }
        current=current->LC;
    }
   
    else
    {
        printf("Data already exists\n");
        f=1;
    }
   
     }while(f!=1);
    }

}

void Inorder(BST *r)
{
    if(r==NULL)
        printf("The tree is empty !!\n");
   
    else
    {
       if(r->LC!=NULL) 
        Inorder(r->LC);
       
        printf("%s ",r->data);
       
              
        if(r->RC!=NULL)
        Inorder(r->RC);
    }
   
}
