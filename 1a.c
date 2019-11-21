#include<stdio.h>
#include<malloc.h>
main()
{

int i,n;
float sum=0,*p;
printf("enter n\n");
scanf("%d",&n);

p=(float*)malloc(n*sizeof(float));
if(p==NULL)
{
 printf("allocation failed\n");
 return;
}
printf("enter %d nos\n",n);
for(i=0;i<n;i++)
  		 scanf("%f",(p+i));

for(i=0;i<n;i++)
  		 sum=sum+ *(p+i);

printf("sum=%f", sum);
}
