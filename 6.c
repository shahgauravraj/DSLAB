#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct student{
				char name[20];
				char USN[10];
	           };
struct stack{
	        struct student stud[SIZE];
			int top;
		};


void push(struct stack *ps,  struct student st1);
struct student pop(struct stack *ps);

void main()
{
struct stack s;
struct student st1,rt1;
int choice,i;
s.top=-1;

do{
	printf("\n 1:PUSH\t 2:POP\t 3:DISPLAY\t 4:QUIT");
	printf("\n Enter your choice:");
	scanf("%d",&choice);
	
switch(choice)
	{
	case 1: printf("Enter the name and USN of student to push:");
			scanf("%s %s",st1.name,st1.USN);
			push(&s,st1);
			break;

	case 2: rt1=pop(&s);
			 printf("The student popped is %s with USN %s\n",rt1.name,rt1.USN);
			break;

	case 3: if(s.top==-1)
				printf("\n Stack empty");
		else
{
				printf("Stack contents are:\n");
				for(i=s.top;i>=0;i--)
				{
					printf("%s %s\n",s.stud[i].name,s.stud[i].USN);
				}
		   }
				break;

	case 4: 	printf("QUITTING OPERATION STACK ..........\n");
		    break;

	default :printf("No such option\n");
	}

	}while(choice!=4);
}


void push(struct stack *ps,  struct student st1)
{
	if(ps->top==SIZE-1)
		printf("Stack Overflow\n");
	else
	{
		++(ps->top);	
		strcpy(ps->stud[ps->top].name,  st1.name);
		strcpy(ps->stud[ps->top].USN,   st1.USN);
	}
}


struct student pop(struct stack *ps)
{
	struct student r;
	if(ps->top==-1)
	{
		printf("\n Stack Underflow");
		exit(1);
	}
		strcpy(r.name,   ps->stud[ps->top].name);
		strcpy(r.USN,   ps->stud[ps->top].USN);
		(ps->top)--;
		return(r);
}
