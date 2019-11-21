#include<stdio.h>
#include<malloc.h>
void main()
{
int i,j,m,n,d1=0,d2=0, sum=0;
int (*p)[3];

printf("Enter row and column\n");
scanf("%d%d",&m,&n);

if(m!=n)
{
 	 printf("not a square matrix\n");
 	 return;
}
p=(int*)malloc(m*n*sizeof(int));

printf("Enter matrix elements\n");
for(i=0;i<m;i++)
  for(j=0;j<n;j++)
  		  scanf("%d",*(p+i)+j);

for(i=0;i<m;i++)
  	  d1=d1+*(*(p+i)+i);

for(i=0,j=(n-1);i<m;i++,j--)
  	 d2=d2+*(*(p+i)+j);

for(i=0;i<m;i++)
 	 for(j=0;j<n;j++)
   		  sum+= *(*(p+i)+j);

printf("the primary matrix is = %d\n",d1);
printf("the secondary matrix is = %d\n",d2);
printf("the sum of all elements is = %d\n",sum);
}

