#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char string[100];
    int freq;
    struct node *next;
}Node;

int insert(Node **H,char *w)
{
	Node *x;
    if((*H)==NULL)
    {
        (*H)=(Node*)malloc(sizeof(Node));
        strcpy((*H)->string,w);
        (*H)->freq=1;
        (*H)->next=NULL;
    }
    else
    {
        Node *current=*H,*prev=NULL;
        while(current!=NULL)
        {
                if(strcmp(w,current->string)==0)
                {
                    current->freq=(current->freq)+1;
                    break;
                }
			    x=current;
				current=current->next;
        }
        if(current==NULL)
        {
            x->next=(Node*)malloc(sizeof(Node));
            strcpy(x->next->string,w);
            x->next->freq=1;
            x->next->next=NULL;
        }
    }
    return 0;
}

int display(Node **H)
{
    if((*H)==NULL)
    printf("Error !!");
    else
    {
        Node *current=*H;
        while(current!=NULL)
        {
            printf("%s\t%d",(current->string),(current->freq));
            current=current->next;
            printf("\n");
        }
    }
    return 0;
}

int main()
{
    int i,j=0,n;
    Node *H=NULL;
    char w[100],a[100];
    printf("Enter string:");
    gets(w);
    printf("Enter the length of the word :");
    scanf("%d",&n);
    for(i=0;i<strlen(w);i++)
    {
        if(w[i]==' ')
        {
            a[j]='\0';
            if(strlen(a)==n)
            insert(&H,a);
            j=0;
        }
        else if(i==strlen(w)-1)
        {
            a[j]=w[i];
            j++;
            a[j]='\0';
            if(strlen(a)==n)
            insert(&H,a);
        }
        else if((w[i]!=' ')&&(i!=strlen(w)-1))
        {
            a[j]=w[i];
            j++;
        }
    }
    display(&H);
    return 0;
}
