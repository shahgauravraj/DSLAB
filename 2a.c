#include<stdio.h>
#include<malloc.h>
void main()
{
int i,j,k,m,n,p,q,sum;
int *A[3],*B[3],*C[3];
printf("enter the order of matrix 1\n");
scanf("%d%d",&m,&n);
printf("enter the order of matrix 2\n");
scanf("%d%d",&p,&q);
if(n!=p)
{
	printf("matrices cannot be multiplied\n");
	return;
}
for(i=0;i<m;i++)
{
  A[i]=(int*)malloc(n*sizeof(int));
 	 C[i]=(int*)malloc(q*sizeof(int));
}

for(i=0;i<p;i++)
{
B[i]=(int*)malloc(q*sizeof(int));
}

printf("enter elements of matrix 1\n");
for(i=0;i<m;i++)
  for(j=0;j<n;j++)
 		   scanf("%d",A[i]+j);

printf("enter elements of matrix 2\n");
for(i=0;i<n;i++)
  for(j=0;j<q;j++)
  		  scanf("%d",B[i]+j);
for(i=0;i<m;i++)
	for(k=0;k<q;k++)
	{
		   *(C[i]+k)=0; 
		   for(j=0;j<n;j++)
        			   *(C[i]+k)= *(C[i]+k)+ *(A[i]+j)* *(B[j]+k);
	   }
/*display*/

for(i=0;i<m;i++)
{
 	 for(j=0;j<q;j++)
   		 printf("%d\t",*(C[i]+j));
  
 		 printf("\n");
}
}
