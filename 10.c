#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int rpt=1,q[SIZE];
int ch;
int frnt,rear;

void main()
{
	frnt=rear=-1;
	while(rpt)
	{
		printf("A Call center phone system using static QUEUE\n");
		printf("select a operation from the followings:\n");
		printf("1:ADD incoming call\n2:REMOVE the call for service\n3:Display pending calls\n4:EXIT\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: insert();
			break;
			case 2: del();
			break;
			case 3: show();
			break;
			case 4: printf("END\n"); exit(0);
			break;
			default: printf("Please enter correct choice\n");
		}	
		printf(" \nTo continue press non zero digit:\n");
		scanf("%d",&rpt);
	}
}

int insert()
{
	int n;
	
	if(rear==(SIZE-1))
	{
		printf("ALREADY QUEUE IS FULL:\n");
		return;
	}

	printf("Enter the call ID to be inserted to the system:\n");
	scanf("%d",&n);

	if(frnt==-1&&rear==-1)
	{
		rear++;frnt++;
		*(q+rear)=n;
		printf("success\n");
	}
	else
	{
		rear++;
		*(q+rear)=n;
		printf("success\n");
	}
	return;
}

int  del()
{	
	int temp;
	if(frnt==-1)
	{	
		printf("no calls waiting in the queue:\n");
		return;
	}
	temp=*(q+frnt);
	frnt++;
	printf("Call answered is %d\n",temp);

	if(frnt > rear)
	frnt=rear=-1;

	return;
}

int show()
{
	int i;
	if(frnt==-1 && rear==-1)
	{
		printf("Sorry no pending calls\n");
		return;
	}
	printf("Here is the waiting queue of calls:\n");
	printf("FRONT\t");
	for(i=frnt;i<=rear;i++)
		printf("%d\t",*(q+i));
	printf("REAR\n");
	return;
}
