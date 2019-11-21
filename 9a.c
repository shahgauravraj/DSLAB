#include<stdio.h>
#include<stdlib.h>

/*binary search*/
int R_bin_search(int a[], int key, int low, int high)
{
  	int mid;

  	if(low>high) return -1;

 	 mid=(low+high)/2;
 
 	if(key==a[mid]) 
		return mid;
  
	if(key<a[mid])  	
		return(R_bin_search(a,key,low,(mid-1)));

 	return(R_bin_search(a,key,(mid+1),high));
}

void main()
{
  int key,*a,i,n,res, repeat, p;

  do{
		printf("ENTER n\n");
  		scanf("%d",&n);

		a=(int*)malloc(n*sizeof(int));
  	
		printf("ENTER THE NUMBERS\n");
 		 for(i=0;i<n;i++)
   			 scanf("%d",(a+i));

	//checking whether it is sorted.
	p=0;	
	for(i=0;i<n-1;i++)
		if(a[i]<a[i+1])p++;

	if(p==n-1)
		printf("Yes. It is sorted in ascending order\n");
           else 
	  {		
		printf("Input is not sorted.Enter numbers in ascending order\n");
		goto AGAIN;
	}

  	printf("ENTER THE KEY TO BE SEARCHED\n");
 	scanf("%d",&key);

 	res=R_bin_search(a,key,0,(n-1));
 	if(res==-1)
    		printf("KEY NOT FOUND\n");
  	else
   		 printf("%d FOUND AT LOCATION %d\n",key,(res+1));
	
AGAIN:
		printf("Press 1 to continue\n");
		scanf("%d",&repeat);
     }while(repeat==1);
}
