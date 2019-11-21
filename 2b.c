#include<stdio.h>
#include<malloc.h>
#include<string.h>
void main()
{ int i,j,n;
 char *names[10],temp;
 
printf("enter n\n");
 scanf("%d",&n);

 for(i=0;i<n;i++)
  	 names[i]=(char*)malloc(80*sizeof(char));

/*reading n names*/
 printf("enter %d names\n",n);
 	getchar();

 for(i=0;i<n;i++)
 	  gets(names[i]);

/*bubble sort*/
 for(i=1;i<n;i++)
   for(j=0;j<(n-i);j++)
     		if(strcmp(names[j],names[j+1])>0)
    		 {	 temp=names[j];
       			 names[j]=names[j+1];
 				 names[j+1]=temp;
    		 }
     /*display*/
 printf("sorted array of names \n");
 for(i=0;i<n;i++)
  	 puts(names[i]);
}
