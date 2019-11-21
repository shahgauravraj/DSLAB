#include<stdio.h>
#include<stdlib.h>

struct stud
{
	int id;
	char name[10];
	int sem;
	struct stud *next;
};

typedef struct stud NODE;

NODE *head;
NODE* insert_f();

void main()
{
	int rpt=1;
	int ch;

	while(rpt)
	{
		printf("select a singly linked list operation from the followings:\n");
		//printf("1:insert at the front\n2:delete at the end\n3:Display\n4:EXIT\n");
		printf("1: Insert a new name \n2: Delete a specified name \n3:Display\n4:EXIT\n");

		scanf("%d",&ch);

	switch(ch)
	{
		case 1: insert_f();
		break;
		case 2: del_e();
		break;
		case 3: show();
		break;
		case 4: printf("END\n"); exit(0);
		break;
		default: printf("please enter correct choice\n");
	}	
	printf(" \nTo continue press non zero digit:\n");
	scanf("%d",&rpt);
	}
}

//end of main()----------------------------------------------------------------

NODE* insert_f()
{
	NODE *n, *m, *temp1, *temp2;
	n=(NODE *)malloc(sizeof(NODE));

	printf("enter student's data in order:\n");
	printf("student ID\n");
	scanf("%d",&n->id);

	printf("student name\n");
	scanf("%s",n->name);

	printf("semester:\n");
	scanf("%d",&n->sem);
	
	n->next=NULL;

if(head==NULL)

	head=n;

else if(strcmp(head->name, n->name)>0)
{
	n->next=head;
	head=n;
}
else
{
	for(temp1=NULL, temp2=head;
 temp2!= NULL && strcmp(n->name,temp2->name)>0;
temp2=temp2->next)
			{
			temp1=temp2;
			}

	temp1->next=n;
	n->next=temp2;	
}
return(head);
}

//---end of insert()------------------------------------------------
del_e()
{
	NODE *temp1,*temp2;
	char name[10];
	int flag=0;
	if(head==NULL)
	{
		printf("empty\n");
		return;
	}

	printf("enter student name for deletion\n");
	scanf("%s",name);

	if(strcmp(head->name,name)==0)
	{
		head=head->next;
		printf("deleted\n");
	}

	else 
	{
		for(temp1=NULL,temp2=head;temp2!=NULL;temp2=temp2->next)
		{
			if(strcmp(name,temp2->name)==0)
			{
				flag=1;
				break;
			}
			else
				temp1=temp2;
		}

	if(flag==0)
	{
		printf("Student name %s 's record not present in the list\n",name);
		return;
	}

	temp1->next=temp2->next;
	printf("%s student's data has been deleted\n",temp2->name);
	free(temp2);
}
return;
}
//-end of delete()-------------------------------------------------------

show()
{
	NODE *N;
	if(head==NULL)
	{
		printf("EMPTY\n");
		return;
	}
	
	printf("%-15s%-20s%-10s\n”,”NAME”,”ID	“,”SEM");
	N=head;

	while(N!=NULL)
	{
		printf("%-15s%-20d%-10d\n”,N->name,N->id,N->sem");
		N=N->next;
	}

	return;
}
