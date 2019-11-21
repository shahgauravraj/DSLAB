#include<stdio.h>

/*strcopy()*/
void strcopy(char *s1,char *s2)
{
	 while(*s2!='\0')
 	{
 		  *s1=*s2;
  		 s1++;
		   s2++;
 	}
	 *s1='\0';
 }

/*strcomp()*/
int strcomp(char *s1,char *s2)
{
	 while(*s1!='\0'||*s2!='\0')
 	{ 
   		if(*s1!=*s2)
   		 	 return(*s1-*s2);
  		 s1++;
 		 s2++;
	 }
 return 0; /*strings are equal*/
}

/*strconcat()*/
void strconcat(char *s1,char *s2)
{
	 while(*s1!='\0')
		   s1++;
	 while(*s2!='\0')
	 {
  		*s1=*s2;
   		s1++;
  		s2++;
 	}
 *s1='\0';
} 

void Strreverse(char *s1)
{
	int i=0,j,k=0;char s3[50];
	 while(*s1)
	{
		s1++,k++;
	}
	 for(i=0,j=k-1;    j>=0;    j--,i++)
	 {
		--s1;
 		  s3[i]=*s1;
             }  	 
	 s3[i]='\0';
	 strcopy(s1,s3);
} 

int main()
{
 char s1[80],s2[80],t1[80];
 int choice, result;

 printf("enter 2 strings\n");
 gets(s1);
 gets(s2);

 strcopy(t1,s1);
 printf("---------MENU-----------\n");
 printf("\n1.strcomp\n2.strcopy\n3.strconcat\n4.Sting reverse\n");
 for(;;)
 {
   printf("enter your choice\n");
   scanf("%d",&choice);
   
   switch(choice)
      {
    case 1: strcopy(s1,t1);
	          result=strcomp(s1,s2);
                if(result>0)
               		 printf("%s is greater than %s\n",s1,s2);
                else if(result<0)
               		 printf("%s is greater than %s\n",s2,s1);
                else
                           printf("strings are equal\n");
	           break;


    case 2:  strcopy(s1,t1);
                 printf("strings before copying, s1=%s\t, s2=%s\n",s1,s2);
	           strcopy(s1,s2);
                 printf("after copying, s1= %s\t, s2= %s\n",s1,s2);
                 break;      

    
    case 3:  strcopy(s1,t1);
	           printf("strings before concatenation, s1=%s\t , s2=%s\n",s1,s2);
	           strconcat(s1,s2);
                 printf("after concatenation, s1= %s\t , s2= %s\n",s1,s2);
                 break;


    case 4:  strcopy(s1,t1);
	           printf("strings before reversing, s1=%s\t , s2=%s\n",s1,s2);
                 printf(" strings after reversing\n");
	           Strreverse(s1);
                 printf("s1=%s\n",s1);
                 strcopy(s1,s2);
	           Strreverse(s1);
                printf("s2=%s\n",s1);
	           break;

  default:  return;
   }
 }
} 
