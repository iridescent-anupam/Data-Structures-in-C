#include<stdio.h>

int main()
{
 int t;
 int i,j,k;
 int table[68][5];

  for(int i=0;i<=68;i++)
   {
    for(int j=0;j<5;j++)
	{
	 table[i][j]=0;
	}
   }

  do
   {
    printf("Enter 1 to make an Entry\n");
	printf("Enter 2 to delete an Entry\n");
	printf("Enter 3 to update an Entry\n");
	printf("Enter 4 to view the Database Table\n");
	scanf("%d",&k);

	switch(k)
	{
	 case 1 : printf("Enter the Store number - \n");
	          scanf("%d",&i);
			  printf("Enter the Department number - \n");
              scanf("%d",&j);
			  printf("Enter the Sales number - \n");
              scanf("%d",&table[i][j]);

     break;

	 case 2 : printf("Enter the Store number - \n");
              scanf("%d",&i);
              printf("Enter the Department number - \n");
              scanf("%d",&j);
              printf("Sales data deleted\n");
              table[i][j]=0;
      
	 break;

	 case 3 : printf("Enter the Store number - \n");
              scanf("%d",&i);
              printf("Enter the Department number - \n");
              scanf("%d",&j);
              printf("Enter the Sales number - \n");
              scanf("%d",&table[i][j]);

     case 4 : for(int i=0;i<68;i++)
			  {
			   for(int j=0;j<5;j++)
	           {
				printf("%d ",table[i][j]);
			   }
			   printf("\n");
			  }

	 break;

	 default : ("Invalid Entry\n");
    }

    printf("Enter 1 if you wish to continue for more changes - ");
    scanf("%d",&t);
   
   }while(t==1);

  return 0;
 }
